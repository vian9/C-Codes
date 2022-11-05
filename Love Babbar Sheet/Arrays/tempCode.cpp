sort(arr1.begin(), arr1.begin() + n);
    sort(arr2.begin(), arr2.begin() + m);
    for (int i = 0; i < m; i++)
    {
        int low = lower_bound(arr1.begin(), arr1.begin() + n, arr2[i]);
        if (arr1[low] == arr2[i])
        {
            arr1[low] = -1;
            arr2[i] == -1;
        }
        else
        {
            return false;
            break;
        }
    }
    return true;