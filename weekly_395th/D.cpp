// 这题不会，先抄了
class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        typedef long long LL;
        int n=nums.size();
        LL k=((LL)n*(n+1)/2+1)/2;
        auto check=[&](int upper){
            LL cnt=0;
            int l=0;
            unordered_map<int,int> freq;
            for(int i=0;i<n;i++){
                freq[nums[i]]++;
                while(freq.size()>upper){
                    int out=nums[l++];
                    if(--freq[out]==0){
                        freq.erase(out);
                    }
                }
                cnt+=i-l+1;
                if(cnt>=k){
                    return true;
                }
                
            }
            return false;
        };
        int l=1,r=n;
        while(l<r){
            int mid=l+r>>1;
            if(check(mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
