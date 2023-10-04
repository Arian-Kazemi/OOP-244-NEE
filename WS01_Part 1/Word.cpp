#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Word.h"

using namespace std;

const int MAX_NO_OF_WORDS = 500;

namespace sdds {

    void programTitle() {
        cout <<
            "This program reads a text file from the standard input and analyzes and reports" << endl <<
            "the number of words and their occurrences in the text file." << endl;
    }

    void wordStats(bool logOn) {
        Word words[MAX_NO_OF_WORDS] = { {"",0} };
        char word[MAX_WORD_LEN];
        char lower_Case_Word[MAX_WORD_LEN];
        int NoOfWords = 0;
        int maximumLen = 0;
        int Index_found = 0;
        while (!cin.fail()) {
            cin >> word;
            toLowerCaseAndAlphabeticCopy(lower_Case_Word, word);
            if (lower_Case_Word[0] != 0) {
                if (maximumLen < (int)strlen(lower_Case_Word)) {
                    maximumLen = strlen(lower_Case_Word);
                }
                if (NoOfWords == 0) {
                    addWord(words, &NoOfWords, lower_Case_Word);
                }
                else {
                    Index_found = searchWords(words, NoOfWords, lower_Case_Word);
                    if (Index_found < 0) { 
                        Index_found = NoOfWords;
                        addWord(words, &NoOfWords, lower_Case_Word);
                    }
                    else {
                        words[Index_found].count++;
                    }
                }
                if (logOn) {
                    print(&words[Index_found], false);
                    cout << " read so far." << endl;
                }
            }
        }
        cout << "---------------------------------------------------" << endl << "End of data" << endl << "---------------------------------------------------" << endl;
        cout << "Sorting data " << endl;
        sort(words, NoOfWords);
        cout << "Sort ended" << endl;
        report(words, NoOfWords, maximumLen);
    }

    void addWord(Word words[], int* index, const char newWord[]) {
        strcpy(words[*index].letters, newWord);
        words[*index].count++;
        (*index)++;
    }

    int searchWords(const Word words[], int num, const char word[]) {
        int i;
        int foundIndex = -1;  
        for (i = 0; foundIndex == -1 && i < num; i++) { 
            if (strcmp(words[i].letters, word) == 0) { 
                foundIndex = i;   
            }
        }
        return foundIndex;
    }

    void print(const Word* w, bool gotoNextLine) {
        cout << w->letters << ": " << w->count;
        if (gotoNextLine) cout << endl;
    }

    void sort(Word words[], int cnt) {
        int i, j;
        for (i = 0; i < cnt - 1; i++) {
            for (j = 0; j < cnt - i - 1; j++) {
                if (strcmp(words[j].letters, words[j + 1].letters) > 0) {
                    swap(&words[j], &words[j + 1]);
                }
            }
        }
    }

    void report(const Word words[], int noOfWords, int longestWord) {
        int i;
        int total;
        title();
        for (total = 0, i = 0; i < noOfWords; i++) {
            print(&words[i], true);
            total += words[i].count;
        }
        endList();
        totalWordsStat(noOfWords, total, longestWord);
    }

    void swap(Word* p1, Word* p2) {
        Word w;
        w = *p1;
        *p1 = *p2;
        *p2 = w;
    }
}
