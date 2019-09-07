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
