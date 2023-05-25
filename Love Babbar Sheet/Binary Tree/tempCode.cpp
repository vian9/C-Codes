 rightVec.insert(rightVec.begin(), inorder[ind + 1], inorder.end());
    buildRemTree(rightRoot, rightVec, postorder);
    TreeNode *leftRoot = new TreeNode(postorder[postorder.size() - 1]);
    postorder.pop_back();
    vector<int> leftVec;
    leftVec.insert(leftVec.begin(), inorder.begin(), inorder[ind - 1]);
    buildRemTree(leftRoot, leftVec, postorder);