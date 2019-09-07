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
