int zAlgorithm(string s, string p, int n, int m)
{
    // Write your code here
    int occurrences = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == p[0])
        {
            if (s.substr(i, m) == p)
                ++occurrences;
        }
    }
    return occurrences;
}

// int zAlgorithm(string s, string p, int n, int m)
// {
// 	// Write your code here
// 	string find = p + "@" + s;
// 	int flen = find.length();
// 	vector<int> z;
// 	for(int i=0;i<flen;i++){
// 		if(i<=m) z.push_back(0);
// 		else{
// 			int start = 0, end = 0;
// 			if(find[i]==find[start]) end=i;
// 			while(end<flen && find[start]==find[end]){
// 				start++;
// 				end++;
// 			}
// 			z.push_back(start);
// 		}
// 	}
// 	int occurrences = 0;
// 	for(int i=m+1;i<flen;i++){
// 		if(z[i]==m) ++occurrences;
// 	}
// 	return occurrences;
// }