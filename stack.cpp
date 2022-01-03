class Solution {

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>mp;
        stack<int>st;
        st.push(nums2[0]);
        for(int i=1;i<nums2.size();i++){
            if(st.top()<nums2[i]){
                while(st.size()>0 && st.top()<nums2[i]){
                mp[st.top()]=nums2[i];
                st.pop();                 
                }
                st.push(nums2[i]);
            }
            else{
                st.push(nums2[i]);
            }
        }
        vector<int>v;
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])!=mp.end()){
                v.push_back(mp[nums1[i]]);
            }
            else v.push_back(-1);
        }
        return v;
    }
};
