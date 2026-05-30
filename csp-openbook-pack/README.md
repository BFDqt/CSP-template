# CSP 开卷救命资料包

这是一套为 CCF CSP（专业级/大学版）设计的“纸质开卷救命资料包”。目标是让临场记忆力差、代码能力弱的考生，依靠检索与模板稳定拿到 Q1/Q2，尽量吃到 Q3 与 Q4/Q5 的部分分。

## 构建
1. 进入目录：
   - `cd csp-openbook-pack`
2. 运行构建脚本：
   - `python build.py`

脚本会生成三份合并版 Markdown（在 output/），若检测到 `pandoc` 则自动生成 PDF。

## 输出产物
- output/csp_openbook_full.md
- output/csp_openbook_quick_cards.md
- output/csp_openbook_code_templates.md
- 若支持：对应的 PDF 文件

## 写作与合并约定
- docs/：章节源文件
- templates/cpp/：可直接照抄的 C++17 模板
- docs 中可使用 `{{include:templates/cpp/xxx.cpp}}` 引用模板，构建脚本会展开为代码块

## 推荐打印方式
见 docs/99_printing_index.md。
