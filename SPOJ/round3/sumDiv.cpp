#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <unordered_set>

typedef long long ll;
using namespace std;

// Greatest Common Divisor (GCD) function
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Modular exponentiation
ll mod_pow(ll base, ll exp, ll mod)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Pollard's Rho Algorithm
ll pollard_rho(ll n)
{
    if (n % 2 == 0)
        return 2;

    ll x = rand() % n;
    ll y = x;
    ll c = rand() % n;
    ll d = 1;

    while (d == 1)
    {
        x = (mod_pow(x, 2, n) + c + n) % n;
        y = (mod_pow(y, 2, n) + c + n) % n;
        y = (mod_pow(y, 2, n) + c + n) % n;
        d = gcd(abs(x - y), n);

        if (d == n)
            break;
    }

    return d;
}

// Miller-Rabin Primality Test
bool miller_rabin(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    ll r = 0;
    ll s = n - 1;
    while (s % 2 == 0)
    {
        s /= 2;
        r++;
    }

    for (ll i = 0; i < 5; i++)
    {
        ll a = 2 + rand() % (n - 3);
        ll x = mod_pow(a, s, n);

        if (x == 1 || x == n - 1)
            continue;

        for (ll j = 1; j < r; j++)
        {
            x = mod_pow(x, 2, n);
            if (x == n - 1)
                break;
            if (x == 1)
                return false;
        }

        if (x != n - 1)
            return false;
    }

    return true;
}

// Prime Factorization using Pollard's Rho and Miller-Rabin
std::vector<ll> prime_factorization(ll num)
{
    std::vector<ll> prime_factors;
    std::unordered_set<ll> factors_set;

    while (num % 2 == 0)
    {
        factors_set.insert(2);
        num /= 2;
    }

    while (num > 1)
    {
        ll prime_factor = pollard_rho(num);

        while (!miller_rabin(prime_factor))
        {
            prime_factor = pollard_rho(prime_factor);
        }

        factors_set.insert(prime_factor);
        num /= prime_factor;
    }

    prime_factors.assign(factors_set.begin(), factors_set.end());

    return prime_factors;
}

int main()
{
    srand(time(0));

    ll n, ans = 1;
    std::cin >> n;

    std::vector<ll> prime_factors = prime_factorization(n);

    for (ll factor : prime_factors)
    {
        ans *= factor;
    }
    cout << ans << endl;

    return 0;
}