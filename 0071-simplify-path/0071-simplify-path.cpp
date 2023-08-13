class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        vector<string> dir;
        
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') continue;
            
            string aux = "";
            while (i < path.size() && path[i] != '/') aux.push_back(path[i++]);
            
            if (aux == ".." && dir.size()) dir.pop_back();
            else if (aux != "." && aux != "..") dir.push_back(aux);
        }
        
        for (int i = 0; i < dir.size(); i++) {
            res.push_back('/');
            res += dir[i];
        }
        
        return res.size() ? res : "/";
    }
};