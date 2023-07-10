
vector<vector<int>> zigzagTraversal(Node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;
    queue<Node *> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> r(size);
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            int index = flag ? i : (size - i - 1);
            r[index] = node->data;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        flag = !flag;
        result.push_back(r);
    }
    return result;
}