if (ans.size() > front.second + 1)
        {
            if (front.first->left)
            {
                ans[front.second + 1].push_back = (front.first->left->val);
                qs.push({front.first->left, front.second + 1});
            }
            if (front.first->right)
            {
                ans[front.second + 1].push_back = (front.first->right->val);
                qs.push({front.first->right, front.second + 1});
            }
        }
        else
        {
            vector<int> temp;
            if (front.first->left)
            {
                temp.push_back(front.first->left->val);
                qs.push({front.first->left, front.second + 1});
            }
            if (front.first->right)
            {
                temp.push_back(front.first->right->val);
                qs.push({front.first->right, front.second + 1});
            }
            if (temp.size() > 0)
                ans.push_back(temp);
        }