    vector<int> v(nums.begin(), nums.end());
  //  sort(v.begin(), v.end());

    for(int i=0;i<n;i++) {
        if (i-1>=0 && i+1<n && (v[i-1]+v[i+1])%2==0 && (v[i-1]+v[i+1])/2==v[i]) {
            swap<int>(v[i], v[i-1]);
        }
    }

    return v;
}