#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

struct Node
{
public:
    string str;
    vector<struct Node*> neighbors;
};

class Solution {
public:
    bool check(string & first,string& second)
    {
        int count = 0;
        for(unsigned int i = 0; i < first.size(); ++i)
        {
            if (first[i] != second[i]) count++;
        }
        return count == 1 ? true : false;
    }
    void buildGraph(Node *head,unordered_set<string> &dictionary,unordered_set<string>& sign)
    {
        unordered_set<string>::iterator itr = dictionary.begin();
        for(; itr != dictionary.end(); ++itr)
        {
            string curstr = *itr;
            if (sign.find(curstr) == sign.end() && check(head->str, curstr))
            {
                sign.insert(curstr);
                Node *node = new Node;
                node->str = curstr;
                node->neighbors.push_back(head);
                head->neighbors.push_back(node);
                buildGraph(node,dictionary,sign);
            }
        }
    }
    Node *getNode(Node *head,string input,unordered_set<string>& sign)
    {
        if (head->str == input) return head;
        sign.insert(head->str);
        for(unsigned int i = 0; i < head->neighbors.size(); ++i)
        {
            if (sign.find(head->neighbors[i]->str) == sign.end())
            {
                Node *node = getNode(head->neighbors[i],input,sign);
                if (node != NULL) return node;
            }
        }
        return NULL;
    }

    int getMinLength(Node *start,Node *end)
    {
        unsigned int mindepth = -1;
        for(unsigned int i = 0; i < start->neighbors.size(); ++i)
        {
            unordered_set<string> sign;
            sign.insert(start->str);

            queue<Node *> strQueue;
            strQueue.push(start);
            unsigned int depth = 1;
            while(!strQueue.empty())
            {
                Node*cur = strQueue.front();
                sign.insert(cur->str);

                strQueue.pop();
                depth++;
                if (cur == end)
                {
                    break;
                }
                for(unsigned int i = 0; i < cur->neighbors.size(); ++i)
                {
                    if (sign.find(cur->neighbors[i]->str) != sign.end())
                    {
                        strQueue.push(cur->neighbors[i]);
                    }
                }
            }
            if (mindepth > depth) mindepth = depth;
        }
        return mindepth;
    }
    void search(Node *start,Node *end,vector<vector<string>> &result)
    {
        int mindepth = getMinLength(start,end);

        for(unsigned int i = 0; i < start->neighbors.size(); ++i)
        {
            vector<string> tmpresult;
            unordered_set<string> sign;
            tmpresult.push_back(start->str);
            sign.insert(start->str);

            queue<Node *> strQueue;
            queue<vector<string>> resQueue;
            resQueue.push(tmpresult);
            strQueue.push(start->neighbors[i]);
            int depth = 1;
            while(!strQueue.empty())
            {
                Node*cur = strQueue.front();
                tmpresult = resQueue.front();
                tmpresult.push_back(cur->str);
                sign.insert(cur->str);

                resQueue.pop();
                strQueue.pop();
                depth++;
                if (cur == end && depth == mindepth)
                {
                    result.push_back(tmpresult);
                    break;
                }
                for(unsigned int i = 0; i < cur->neighbors.size(); ++i)
                {
                    if (sign.find(cur->neighbors[i]->str) != sign.end())
                    {
                        strQueue.push(cur->neighbors[i]);
                        resQueue.push(tmpresult);
                    }
                }
            }
        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dictionary)
    {
        dictionary.insert(start);
        dictionary.insert(end);
        unordered_set<string> sign;

        Node *head = new Node;
        head->str = (*dictionary.begin());
        sign.insert(head->str);
        buildGraph(head,dictionary,sign);

        sign.clear();
        Node *startnode = getNode(head,start,sign);
        sign.clear();
        Node *endnode = getNode(head,end,sign);

        vector<vector<string>> result;
        search(startnode,endnode,result);

        return result;
    }
};