// Difficulty: Hard

/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:
    A word is defined as a character sequence consisting of non-space characters only.
    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    The input array words contains at least one word.

Example 1:
    Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
    Output:
    [
    "This    is    an",
    "example  of text",
    "justification.  "
    ]

Example 2:
    Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
    Output:
    [
    "What   must   be",
    "acknowledgment  ",
    "shall be        "
    ]
    Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
    Note that the second line is also left-justified because it contains only one word.

Example 3:
    Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
    Output:
    [
    "Science  is  what we",
    "understand      well",
    "enough to explain to",
    "a  computer.  Art is",
    "everything  else  we",
    "do                  "
    ]

Constraints:
    1 <= words.length <= 300
    1 <= words[i].length <= 20
    words[i] consists of only English letters and symbols.
    1 <= maxWidth <= 100
    words[i].length <= maxWidth
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
private:
    void justify(const int i, vector<string>& words, vector<string>& line, int& letter_count,
                 const int maxWidth, vector<string>& ret)
    {
        // Subtract the number of spaces added to the letter count
        letter_count -= line.size();
        int spaces_needed = maxWidth - letter_count;

        string justified_line{};

        // Check for fully-justification conditions:
        //  Has more than one word;
        //  Is not the last line.
        if((line.size() > 1) && (i <= words.size() - 1))
        {
            // Last word won't have spaces after it
            int words_to_add_space = line.size() - 1;
            for(const string& elem : line)
            {
                justified_line += elem;
                if(spaces_needed > 0)
                {
                    int calc{};
                    if(0 == (spaces_needed % words_to_add_space))
                    {
                        calc = spaces_needed / words_to_add_space;
                        justified_line.append(calc, ' ');
                    }
                    else
                    {
                        calc = std::ceil((spaces_needed / words_to_add_space) + 0.5);
                        justified_line.append(calc, ' ');
                    }

                    spaces_needed -= calc;
                    words_to_add_space--;
                }
            }
        }
        // Left-justification
        else 
        {
            for(int j = 0; j < line.size(); ++j)
            {
                justified_line.append(line[j]);
                if(j < line.size() - 1)
                {
                    justified_line.append(" ");
                    spaces_needed -= 1;
                }
            }
            justified_line.append(spaces_needed, ' ');
        }

        ret.push_back(std::move(justified_line));

        line.clear();
        if(i <= words.size() - 1)
        {
            line.push_back(words[i]);
            letter_count = words[i].size() + 1;
        }
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> ret{};
        vector<string> line{};
        int letter_count{0};

        for(int i = 0; i < words.size(); ++i)
        {
            if(letter_count + words[i].size() <= maxWidth)
            {
                line.push_back(words[i]);
                letter_count += words[i].size() + 1; // Sum with space
            }
            else
            {
                justify(i, words, line, letter_count, maxWidth, ret);
            }
        }

        if(line.size() > 0)
            justify(words.size(), words, line, letter_count, maxWidth, ret);

        return ret;
    }
};

int main()
{
    // vector<string> str{"This", "is", "an", "example", "of", "text", "justification."}; // 16

    // vector<string> str{"What","must","be","acknowledgment","shall","be"}; // 16

    vector<string> str{"Science","is","what","we","understand","well","enough","to",
                      "explain","to","a","computer.","Art","is","everything","else","we","do"}; // 20

    Solution s{};
    s.fullJustify(str, 20);

    return 0;
}
