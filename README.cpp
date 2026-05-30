#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <cstdint>
#include <algorithm>
#include <memory>
#include <type_traits>

namespace application::meta {

    template <typename T>
    struct identity {
        using type = T;
    };

    template <std::uint64_t N>
    struct constant_u64 {
        static constexpr std::uint64_t value = N;
    };

    template <typename T>
    concept ByteLike = std::is_same_v<T, char>;

}

namespace application::config {

    inline constexpr const char* target_file_name = "wkr.txt";

    /*
        1.4 GiB ≈ 1503238553.6 bytes
        这里取 1503238554，并且它能被 9 整除，
        不会把 UTF-8 中文字符截断。
    */
    using target_size = meta::constant_u64<1503238554ULL>;

}

namespace application::encoding {

    class Utf8Atom {
    private:
        std::array<char, 9> payload_{};

    public:
        Utf8Atom() noexcept
            : payload_{
                '\xE7', '\x8E', '\x8B',
                '\xE6', '\x81', '\xBA',
                '\xE5', '\xAE', '\xB9'
            } {}

        const char* data() const noexcept {
            return payload_.data();
        }

        std::size_t size() const noexcept {
            return payload_.size();
        }
    };

}

namespace application::buffering {

    template <meta::ByteLike Byte>
    class StaticBlock {
    private:
        std::vector<Byte> storage_;

    public:
        StaticBlock(const encoding::Utf8Atom& atom, std::size_t repeat) {
            storage_.reserve(atom.size() * repeat);

            for (std::size_t i = 0; i < repeat; ++i) {
                storage_.insert(storage_.end(), atom.data(), atom.data() + atom.size());
            }
        }

        const Byte* data() const noexcept {
            return storage_.data();
        }

        std::size_t size() const noexcept {
            return storage_.size();
        }
    };

}

namespace application::io {

    class Sink {
    private:
        std::ofstream stream_;

    public:
        explicit Sink(const char* path)
            : stream_(path, std::ios::binary) {}

        bool valid() const noexcept {
            return static_cast<bool>(stream_);
        }

        bool write(const char* data, std::size_t bytes) {
            stream_.write(data, static_cast<std::streamsize>(bytes));
            return static_cast<bool>(stream_);
        }
    };

}

namespace application::task {

    class Cursor {
    private:
        std::uint64_t current_ = 0;
        std::uint64_t limit_ = 0;

    public:
        explicit Cursor(std::uint64_t limit) noexcept
            : limit_(limit) {}

        bool done() const noexcept {
            return current_ >= limit_;
        }

        std::size_t next(std::size_t block_size) const noexcept {
            const auto remain = limit_ - current_;
            return static_cast<std::size_t>(
                std::min<std::uint64_t>(remain, block_size)
            );
        }

        void advance(std::size_t n) noexcept {
            current_ += n;
        }
    };

    class Executor {
    private:
        encoding::Utf8Atom atom_;
        buffering::StaticBlock<char> block_;

    public:
        Executor()
            : atom_(),
              block_(atom_, 1024 * 1024) {}

        int run() {
            io::Sink sink(config::target_file_name);
            if (!sink.valid()) {
                return 1;
            }

            Cursor cursor(config::target_size::value);

            while (!cursor.done()) {
                const std::size_t n = cursor.next(block_.size());

                if (!sink.write(block_.data(), n)) {
                    return 2;
                }

                cursor.advance(n);
            }

            return 0;
        }
    };

}

int main() {
    application::task::Executor executor;
    return executor.run();
}