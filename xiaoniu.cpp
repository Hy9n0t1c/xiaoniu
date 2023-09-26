#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <random>

using namespace std;

struct Word {
    string word;
    string meaning;
};

vector<Word> wordList;

void addWord() {
    Word newWord;
    cout << "请输入单词：";
    getline(cin, newWord.word);
    cin.ignore(); // 忽略之前的换行符
    cout << "请输入释义：";

    getline(cin, newWord.meaning);
    wordList.push_back(newWord);
    cout << "添加成功！" << endl;
}

void viewWords() {
    if (wordList.empty()) {
        cout << "单词本为空！" << endl;
        return;
    }

    cout << "已添加的单词：" << endl;
    for (const auto& word : wordList) {
        cout << word.word << " - " << word.meaning << endl;
    }
}

void reviewWords() {
    if (wordList.empty()) {
        cout << "单词本为空！" << endl;
        return;
    }

    // 生成随机数，用于选择一个单词进行复习
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, wordList.size() - 1);
    int randomIndex = dis(gen);
    const Word& randomWord = wordList[randomIndex];

    cout << "请写出单词的内容：" << endl;
    cout << randomWord.meaning << endl;
    system("chcp 65001 > null");
    string userAnswer;
    cin.ignore(); // 忽略之前的换行符
    getline(cin, userAnswer);

    if (userAnswer == randomWord.word) {
        cout << "回答正确！奖励一朵小红花！" << endl;
    } else {
        cout << "回答错误！扣除一颗小红花！正确答案是：" << randomWord.word << endl;
    }
}

int main() {
    int choice;
    while (true) {
        system("chcp 65001 > null");
        cout << "欢迎使用小牛单词本！请选择操作：" << endl;
        cout << "1. 添加单词" << endl;
        cout << "2. 查看单词" << endl;
        cout << "3. 复习" << endl;
        cout << "4. 退出" << endl;
        cout << "请输入选项：";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addWord();
                break;
            case 2:
                viewWords();
                break;
            case 3:
                reviewWords();
                break;
            case 4:
                cout << "感谢使用小牛单词本，再见！" << endl;
                return 0;
            default:
                cout << "无效的选项，请重新输入！" << endl;
                break;
        }

        cout << endl;
    }
}
