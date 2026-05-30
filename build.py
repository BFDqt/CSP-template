from __future__ import annotations

from pathlib import Path
import re
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parent
DOCS_DIR = ROOT / "docs"
TEMPLATE_DIR = ROOT / "templates" / "cpp"
OUTPUT_DIR = ROOT / "output"
PDF_TITLE = "CSP 开卷速查与模板包"

DOC_ORDER = [
    "00_exam_strategy.md",
    "01_cpp_survival.md",
    "02_algorithm_router.md",
    "03_q1_q2_basic_patterns.md",
    "04_big_simulation_q3.md",
    "05_graph_templates.md",
    "06_dp_templates.md",
    "07_data_structure_templates.md",
    "08_math_templates.md",
    "09_string_templates.md",
    "10_partial_score_playbook.md",
    "11_debug_checklists.md",
    "12_past_problem_index.md",
    "99_printing_index.md",
]

QUICK_DOCS = [
    "00_exam_strategy.md",
    "02_algorithm_router.md",
    "10_partial_score_playbook.md",
    "11_debug_checklists.md",
]

INCLUDE_RE = re.compile(r"\{\{include:([^}]+)\}\}")


def _read_text(path: Path) -> str:
    return path.read_text(encoding="utf-8")


def _safe_resolve(rel_path: str) -> Path | None:
    candidate = (ROOT / rel_path).resolve()
    if not candidate.exists():
        return None
    if ROOT not in candidate.parents and candidate != ROOT:
        return None
    return candidate


def expand_includes(text: str) -> str:
    def repl(match: re.Match) -> str:
        rel = match.group(1).strip()
        target = _safe_resolve(rel)
        if not target:
            return f"```text\n[缺少文件] {rel}\n```"
        code = _read_text(target)
        return f"```cpp\n{code}\n```"

    return INCLUDE_RE.sub(repl, text)


def join_docs(doc_list: list[str]) -> str:
    parts: list[str] = []
    for name in doc_list:
        path = DOCS_DIR / name
        if not path.exists():
            parts.append(f"# 缺少文件：{name}\n")
            continue
        parts.append(expand_includes(_read_text(path)).strip())
    return "\n\n\\newpage\n\n".join(parts) + "\n"


def render_templates() -> str:
    parts: list[str] = [
        "# C++17 代码模板全集",
        "页眉：模块名=代码模板合集 | 页码=____ | 触发词=模板/照抄",
        "翻页索引：按文件名顺序",
    ]
    for path in sorted(TEMPLATE_DIR.glob("*.cpp")):
        title = path.stem
        parts.append(f"## {title}")
        parts.append(f"```cpp\n{_read_text(path)}\n```")
    return "\n\n".join(parts) + "\n"


def build_toc(text: str) -> str:
    lines = ["# 目录", ""]
    for line in text.splitlines():
        if line.startswith("# "):
            title = line[2:].strip()
            lines.append(f"- {title}")
        elif line.startswith("## "):
            title = line[3:].strip()
            lines.append(f"  - {title}")
    return "\n".join(lines) + "\n\n\\newpage\n\n"


def write_output(name: str, content: str) -> Path:
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    out_path = OUTPUT_DIR / name
    out_path.write_text(content, encoding="utf-8")
    return out_path


def write_pdf_header(title: str) -> Path:
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    header = (
        "\\usepackage{xeCJK}\n"
        "\\setCJKmainfont{SimSun}\n"
        "\\setmonofont{Consolas}\n"
        "\\usepackage{fancyhdr}\n"
        "\\pagestyle{fancy}\n"
        "\\fancyhf{}\n"
        "\\lhead{\\leftmark}\n"
        f"\\rhead{{{title}}}\n"
        "\\cfoot{\\thepage}\n"
        "\\setlength{\\headheight}{14pt}\n"
    )
    header_path = OUTPUT_DIR / "pandoc_header.tex"
    header_path.write_text(header, encoding="utf-8")
    return header_path


def try_pandoc(md_path: Path, pdf_path: Path, title: str) -> bool:
    if not shutil.which("pandoc"):
        return False
    header_path = write_pdf_header(title)
    subprocess.run(
        [
            "pandoc",
            str(md_path),
            "-o",
            str(pdf_path),
            "--pdf-engine=xelatex",
            "--toc",
            "--toc-depth=2",
            "--metadata",
            f"title:{title}",
            "--metadata",
            "toc-title:目录",
            "-H",
            str(header_path),
        ],
        check=False,
    )
    return True


def build_pdf(body: str, pdf_name: str, title: str) -> bool:
    temp_md = write_output(f"{pdf_name}.pdf.md", body)
    pdf_path = OUTPUT_DIR / f"{pdf_name}.pdf"
    ok = try_pandoc(temp_md, pdf_path, title)
    try:
        temp_md.unlink()
    except OSError:
        pass
    return ok


def main() -> int:
    full_body = join_docs(DOC_ORDER) + "\n\n\\newpage\n\n" + render_templates()
    full_md = build_toc(full_body) + full_body

    quick_body = join_docs(QUICK_DOCS)
    quick_md = build_toc(quick_body) + quick_body

    tpl_body = render_templates()
    tpl_md = build_toc(tpl_body) + tpl_body

    full_path = write_output("csp_openbook_full.md", full_md)
    quick_path = write_output("csp_openbook_quick_cards.md", quick_md)
    tpl_path = write_output("csp_openbook_code_templates.md", tpl_md)

    pdf_ok = False
    pdf_ok = build_pdf(full_body, "csp_openbook_full", PDF_TITLE) or pdf_ok
    pdf_ok = build_pdf(quick_body, "csp_openbook_quick_cards", PDF_TITLE) or pdf_ok
    pdf_ok = build_pdf(tpl_body, "csp_openbook_code_templates", PDF_TITLE) or pdf_ok

    if not pdf_ok:
        print("未检测到 pandoc 或 XeLaTeX，已仅生成 Markdown。")

    return 0


if __name__ == "__main__":
    sys.exit(main())
