
        return findLastCommonNode(pathP, pathQ);
    }

private:
    list<TreeNode *> findPathFromRoot(TreeNode *root, TreeNode *target)
    {
        list<TreeNode *> path;
        loadPathFromRootHelper(root, target, path);
        return path;
    }

    bool loadPathFromRootHelper(TreeNode *root, TreeNode *target, list<TreeNode *> &path)
    {
        if (root == nullptr || target == nullptr)
            return false;
        path.push_back(root);
        if (root == target)
            return true;
        if (loadPathFromRootHelper(root->left, target, path) ||
            loadPathFromRootHelper(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode *findLastCommonNode(list<TreeNode *> A, list<TreeNode *> B)
    {
        TreeNode *ans = nullptr;
        for (auto ptrA = A.begin(), ptrB = B.begin();
             ptrA != A.end() && ptrB != B.end();
             ++ptrA, ++ptrB)
        {
            if (*ptrA == *ptrB)
                ans = *ptrA;
            else
            {
                break;
            }
        }
        return ans;
    }
};