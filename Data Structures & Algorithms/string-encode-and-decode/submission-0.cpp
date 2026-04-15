class Solution {
public:

    string encode(vector<string>& strs) {
        string es;
        char start = '*';
        char end = '#';
        for(auto s : strs) {
            int size = s.length();
            es += to_string(size) + start + s + end;
        }
        cout<<es<<endl;
        return es;
    }

    vector<string> decode(string s) {
        vector<string> ds;
        int len = s.length();
        for(int i=0;i<s.length();) {
            string l;
            while(s[i] != '*' && i < len) {
                l += s[i++];
            }
            cout<<"l: "<<l<<endl;
            i++;
            int steps = stoi(l);
            cout<<"Steps: "<<steps<<endl;
            string word;
            while(steps) {
                word += s[i++];
                steps--;
            }
            i++;
            ds.push_back(word);
        }
        return ds;
    }
};
