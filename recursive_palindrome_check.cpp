// recursive palindrome check
bool is_palin(int i, int j, string& s)
{
    if(i==j)
        return true;
    if(s[i]!=s[j])
        return false;
    if(i<j+1)
        return is_palin(i+1, j-1, s);
    return true;
}
