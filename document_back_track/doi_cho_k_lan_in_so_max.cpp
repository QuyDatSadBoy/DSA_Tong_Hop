// Cho số tự nhiên K và xâu ký tự các chữ số S.Nhiệm vụ của bạn là đưa ra số lớn
// nhất bằng cách thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S.
// Ví dụ K = 3 và S = “1234567” ta được “7654321”. int n;
string s;
cin >> n >> s;
while (n--)
{
  int l = 0, r = s.size() - 1, k = r;
  while (l < r && s[l + 1] <= s[l])
    l++;
  if (l == r)
    break;
  while (l < r)
  {
    if (s[r] > s[k])
      k = r;
    r--;
  }
  l = 0;
  while (l < k && s[l] >= s[k])
    l++;
  swap(s[l], s[k]);
}
cout << s << endl;