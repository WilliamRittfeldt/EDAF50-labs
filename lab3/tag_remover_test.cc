#include "tag_remover.h"
#include <iostream>
#include <sstream>
#include <string>

bool testRemoveTags(const std::string& input, const std::string& expectedOutput) {
    std::istringstream inputStream(input);
    TagRemover tr(inputStream);
    std::ostringstream outputStream;
    tr.print(outputStream);
    std::string actualOutput = outputStream.str();
    return actualOutput == expectedOutput;
}

bool testDecodeSpecialChars(const std::string& input, const std::string& expectedOutput) {
    std::istringstream inputStream(input);
    TagRemover tr(inputStream);
    std::ostringstream outputStream;
    tr.print(outputStream);
    std::string actualOutput = outputStream.str();
    return actualOutput == expectedOutput;
}

void runTest(const std::string& testName, const std::string& input, const std::string& expectedOutput, bool (*testFunction)(const std::string&, const std::string&)) {
    bool result = testFunction(input, expectedOutput);
    std::cout << testName << ": " << (result ? "PASS" : "FAIL") << std::endl;
}

int main() {
    runTest("Test Remove Simple Tag", "<h1>Title</h1>", "Title", testRemoveTags);
    runTest("Test Remove Multiple Tags", "<div><p>Paragraph</p><p>Another</p></div>", "ParagraphAnother", testRemoveTags);
    runTest("Test Decode Special Characters", "&lt;div&gt;&amp;&nbsp;&lt;/div&gt;", "<div>& </div>", testDecodeSpecialChars);
    return 0;
}
