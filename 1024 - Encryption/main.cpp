#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int cases;
    std::cin >> cases;
    std::cin.ignore();
    std::string word;
    
    char temp1, temp2;
    while (cases-- > 0)
    {
        getline(std::cin, word);
        size_t size = word.size();
        if(size%2 != 0)
        {
            temp1 = word[size/2];
            if ((temp1 >= 'a' && temp1 <= 'z') || (temp1 >= 'A' && temp1 <= 'Z') )
            {
                word[size/2] += 3;
            }
            word[size/2] -=1;
        }
        for (size_t i = 0; i < size/2; i++)
        {
            temp2 = word[size-1-i];
            temp1 = word[i];
            if ((temp1 >= 'a' && temp1 <= 'z') || (temp1 >= 'A' && temp1 <= 'Z') )
            {
                word[i] += 3;
            }
            if ((temp2 >= 'a' && temp2 <= 'z') || (temp2 >= 'A' && temp2 <= 'Z') )
            {
                word[size-1-i] += 3;
            }
            word[i] -=1;
            std::swap(word[i], word[size-1-i]);
        }

        std::cout << word << "\n";
    }
    std::cout.flush();

}


