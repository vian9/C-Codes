#include<vector>
using namespace std;

template<typename T>
class TreeNode {
public:
    T data;
    // TreeNode ka datatype will be same as jo parents i.e. T
    vector<TreeNode*> children;

    TreeNode(T data) {
        this->data = data;
    }
};