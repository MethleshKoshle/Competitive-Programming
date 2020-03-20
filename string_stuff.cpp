#define all(x) x.begin(), x.end()

// take string input using scanf()
char tmp[101];
scanf("%100s", tmp);
string a= tmp;

//////////// Convert deciaml integer to binary ////////////
inline string bin(int x)
{
    string n="";
    char c;
    while(x)
    {
        c='0'+x%2;
        n = n+string{c};
        x/=2;
    }
    reverse(all(n));
    return n;
}

// convert intger leteral to string
template <class T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

/*convert integer literal to string*/
string itos(ll x){
    string tmp="";
    do{
        tmp+=to_string(x%10);
        x/=10;
    }while(x>0);
    reverse(all(tmp));
    return tmp;
}

//convert string literal to long long int
ll stoI(string n){
    ll tmp=0, fact=1;
    wb(i, n.length()-1, 0, 1){
        tmp+=stoi(string{n[i]})*fact;
        fact*=10;
    }
    return tmp;
}

//aliter
stoi(num);//integer range
stoll(num);//ll range
stoull(num);//ull range

vector<string> get_words_from_line()
{
  string line, s, tmp="";
  vector<string> var;
  getline(cin, line);
  getline(cin, line);
  line+=" ";
  for(auto e:line)
  {
    if(e==' ' and tmp.length())
    {
      var.pb(tmp);
      tmp="";
    }
    else
      tmp+=e;
  }
  return var;
}
bool isSmaller(string str1, string str2){ 
    int n1 = str1.length(), n2 = str2.length(); 
    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
    for (int i=0; i<n1; i++) 
    if (str1[i] < str2[i]) 
        return true; 
    else if (str1[i] > str2[i]) 
        return false; 
    return false; 
} 
string findDiff(string str1, string str2){ 
    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
    int carry = 0; 
    for (int i=0; i<n2; i++) { 
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
        str.push_back(sub + '0'); 
    } 
    for (int i=n2; i<n1; i++){ 
        int sub = ((str1[i]-'0') - carry); 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0;         
        str.push_back(sub + '0'); 
    } 
    reverse(str.begin(), str.end()); 
    return str; 
} 
string modBigNumber(string num, ll m){ 
    vi vec;
    ll mod = 0; 
    for (int i = 0; i < num.size(); i++){ 
        int digit = num[i] - '0'; 
        mod = mod * 10 + digit; 
        int quo = mod / m; 
        vec.push_back(quo);
        mod = mod % m;         
    } 
    string tmp="";
    bool zeroflag = 0; 
    for (int i = 0; i < vec.size(); i++) { 
        if (vec[i] == 0 && zeroflag == 0) 
            continue; 
        zeroflag = 1;
        tmp+=itos(vec[i]);
    }
    if(tmp.length()==0)
        tmp="0";
    return tmp; 
} 
// take mod expo
int mod_pow_s(int x, string p, int mod_v){
    int v = 1;
    while(1){
        if(p=="0")
            break;
        int c=p.back()-'0';
        if(c%2) v = x * v % mod_v;
        x = x * x % mod_v;
        p=modBigNumber(p, 2);
    }
    return v;
}
