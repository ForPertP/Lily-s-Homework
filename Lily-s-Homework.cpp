#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// from https://www.hackerrank.com/challenges/lilys-homework/forum by shiftdel1
int lilysHomework(vector<int> arr)
{
    std::vector<int>arrCopy{arr};
    std::vector<int>sortedAscend{arr};
    std::vector<int>sortedDescend{arr};    
    std::map<int, int>ascendMap;
    std::map<int, int>descendMap;
    int ascend{0};
    int descend{0};
    
    for (int i = 0; i < arr.size(); ++i)
    {
        ascendMap[arr[i]] = i;
        descendMap[arr[i]] = i;
    }
               
    std::sort(sortedAscend.begin(), sortedAscend.end());
    std::sort(sortedDescend.begin(), sortedDescend.end(), greater<int>());
    
    for (int i{0}; i < arr.size(); ++i)
    {
        if (ascendMap[sortedAscend[i]] != i)
        {
            ascendMap[arrCopy[i]] = ascendMap[sortedAscend[i]];
            ascendMap[sortedAscend[i]] = i;
            std::swap(arrCopy[ascendMap[arrCopy[i]]], arrCopy[ascendMap[sortedAscend[i]]]);
            ascend++;
        }
        
        if (descendMap[sortedDescend[i]] != i)
        {
            descendMap[arr[i]] = descendMap[sortedDescend[i]];
            descendMap[sortedDescend[i]] = i;
            std::swap(arr[descendMap[arr[i]]], arr[descendMap[sortedDescend[i]]]);
            descend++;
        }            
    }
    
    return (ascend < descend) ? ascend : descend;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);
    s.erase(
        s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

