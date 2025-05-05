#include<iostream>
#include<vector>
#include <utility>
using namespace std;

class Dictionary{
    vector<pair<int,string>> *dict;

    public:
    Dictionary(int n) {
        dict = new vector<pair<int, string>>[n];
    }

    int hashFunction(int key){
        return key%10;
    }

    void insert(int key,string value) {
        int index=hashFunction(key);
        dict[index].push_back({key,value});
        cout<<"Inserted successfully"<<endl;
    }

    void find(int key){
        int index = hashFunction(key);
        for(auto pair:dict[index]) {
            if(pair.first==key) {
                cout<<"key found ,key: "<<key<<" value: "<<pair.second<<endl;
                return;
            }
        }
        cout<<"Key not found"<<endl;
    }

    void Delete(int key) {
        int index = hashFunction(key);
        for (auto it = dict[index].begin(); it!= dict[index].end();it++){
            if(it->first==key) {
                dict[index].erase(it);
                cout<<"Successfully deleted"<<endl;
                break;
            }
        }
    }

};

int main(){

Dictionary d(10);
d.insert(27, "abc");
d.find(27);
d.Delete(27);
d.find(27);
 return 0;
}