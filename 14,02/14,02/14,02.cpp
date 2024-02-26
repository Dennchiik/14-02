#include <iostream>
#include <string>

class TextCompressor {
private:
    std::string text;

    void removeExtraSpaces() {
        size_t start = 0;
        size_t end = text.size() - 1;

        while (start < text.size() && text[start] == ' ')
            start++;
        while (end > start && text[end] == ' ')
            end--;

        text = text.substr(start, end - start + 1);
        size_t i = 0;
        while (i < text.size()) {
            if (text[i] == ' ') {
                size_t j = i + 1;
                while (j < text.size() && text[j] == ' ')
                    j++;
                if (j - i > 1)
                    text.erase(i + 1, j - i - 1);
            }
            i++;
        }
    }

public:
    TextCompressor(const std::string& input_text) : text(input_text) {}

    void compressText() {
        removeExtraSpaces();
        if (!text.empty()) {
            if (text.back() == ' ')
                text.pop_back();
        }
    }

    std::string getCompressedText() const {
        return text;
    }
};

int main() {
    std::string input_text;
    std::cout << "Введите строку текста: ";
    std::getline(std::cin, input_text);

    TextCompressor compressor(input_text);
    compressor.compressText();

    std::cout << "Сжатый текст: " << compressor.getCompressedText() << std::endl;

    return 0;
}
