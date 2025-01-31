Applications:
==============
        
1. ans = ( a + b ) % m = ( ( a % m ) + ( b % m ) ) % m 


2. ans = ( a - b ) % m = ( a % m ) - ( b % m ) ; 
        if ( ans < 0 ) ans = ( ans + m ) ; 
        ans = ans % m;


3. ans = ( a * b ) % m = ( ( a % m ) * ( b % m ) ) % m 
   ans = ( a * b * c ) = ( ( ( ( a % m ) * b ) % m ) * c ) % m
   
   
   
   
4. Modular Exponentiation or Big MOD : ( pow ( a , b ) % MOD ) or ( a ^ b ) % MOD 
===================================================================================================================================
Easy Solution : ( a ^ b ) হওয়ায় a কে  b সংখ্যক বার লুপ চালিয়ে গুণ করলে ( a ^ b ) পাওয়া যাবে। 
যেমন, ( 3 ^ 5 ) = 3 x 3 x 3 x 3 x 3 ; এক্ষেত্রে ans কে বার বার MOD ( % ) করতে হবে যাতে ans অনেক বড় না হয়।
এই সমাধান সব ক্ষেত্রে কাজ করবে না।

Complexity হবে O ( Power ) ; Power, b = 1e9 হলে এটি 1s এ চলবে না। 

Efficient Solution :

ll power ( ll num , ll pwr , ll mod)
{
    num = num % mod ; /// update num (base) if it's more than MOD.
    if ( num == 0 ) return 0; ///In case num is divisible by power. 

    ll ans = 1 ; /// Initial Result

    while( pwr > 0 )
    {
        if ( pwr & 1 ) ans = (( num % mod ) * ans ) % mod ;/// If power is odd, multiply num with result and make it even. reduce power 1.

        pwr = ( pwr >> 1 ) ;/// power must be even now. pwr = pwr / 2

        num = ( ( num % mod ) * ( num % mod) ) % mod; /// num ^ 2 -> num ^ 4 -> num ^ 8 ......
    }

    return ans;
}

int main()
{
    FAST;
    int b , p , m ;
    cin >> b >> p >> m ; /// input base , power , MOD
    
    ll ans = power( b , p , m ) ;

    cout << ans << endl;
}

Complexity : O ( log ( Power ) ) ,  2 based log

এখানে , Power odd হলে প্রথমেই তাকে Power 1 কমিয়ে even বানানো হয়েছে । সেই অংশ রেজাল্ট এ আগেই যুক্ত করা হয়েছে । 

পাওয়ার যখন জোড় হয় , তখন রেজাল্ট প্রতি ক্ষেত্রে দ্বিগুণ করে আপডেট হতে থাকে। কারণ a ^ 4 এর রেজাল্ট পেয়ে গেলে এর পরবর্তী রেজাল্ট যা পাওয়া যাবে সেটি a^8 এর। মাঝের অংশ নিয়ে 
চিন্তা করা লাগতেছে না। 
সবশেষ এ power = 2 >> 1 = 2 / 2 = 1 হবে যা odd. ইতমধ্যে num এ রেজাল্ট আপডেট হয়ে আছে। শেষ এ odd পাওয়ায় num এর রেজাল্ট মূল রেজাল্ট (ans) এ আপডেট হবে। সেটি রিটার্ন হবে। 
যেমন, 
( num ^ 5 ) % mod. Here , Power = 5 odd.
 So, ans = a // initially.
        Now , power = 5 / 2 = 2 and num = num * num = num ^ 2
        then, power = 2 / 2 = 1 and num = (num ^ 2) * (num ^ 2) = num ^ 4
        then, power odd. So, ans = (num ^ ans) , which is final Result. 
        

        
        
Modular Division Or MOD Inverse:
=========================================================================================
        
Let, ( a / b ) % MOD ; It'll be easy if a is divisible by b; If the result is fractional, such as ( 8 / 7 ), ( 5 / 2 ) etc, Then how can we determine MOD result ? 
 
   Given,  ( a / b ) % MOD , এখানে a or b নেগেটিভ হলে আলাদাভাবে হ্যান্ডেল করতে হবে । ( a % MOD ) + MOD or ( b % MOD ) + MOD
         = (a * ( 1 / b ) ) % MOD
         = ( a * ( b ^ -1 ) ) % MOD = ( ( a % MOD ) * (( b ^ -1 ) % MOD ) % MOD ) . Here, b ^ -1 is b inverse ( 1 / b ). 
         
  Fermats’s little theorem, ( b ^ -1 ) % MOD == ( ( b ^ MOD-2 ) ) % MOD     ---> Equvalent
        Answer  = ( a * Euler Theorem ) % MOD
  
  Example: 
  1. ( 28 / 7 ) % 5 == 4 % 5 == 4
  Prove, ( 28 / 7 ) = 28 * ( 7 ^ -1)
    Now, ( 7 ^ -1) % 5 = ( 7 ^ 5-2 ) % 5 = ( 7 ^ 3 ) % 5 = 343 % 5 = 3
    Ans  = ( a * Euler Theorem ) % MOD = ( ( 28 % 5 ) * ( 3 % 5 ) % 5 ) = ( 3 * 3) % 5 = 9 % 5 = 4 (Ans.) 
          
   উপরের Fermats’s little theorem এ b (বেজ) সব সময় প্রাইম নাম্বার হবে। অন্য কোন  ক্ষেত্রে প্রযোজ্য না। উপরে ৭ প্রাইম হওয়ায় সূত্রটি প্রমাণিত হয়েছে।

Code:
ll B_Inverse ( ll num , ll pwr , ll mod) /// BIG MOD Algo.
{
    num = num % mod ; /// update num (base) if it's more than MOD.
    if ( num == 0 ) return 0; ///In case num is divisible by power.

    ll ans = 1 ; /// Initial Result

    while( pwr > 0 )
    {
        if ( pwr & 1 ) ans = (( num % mod ) * ans ) % mod ;/// If power is odd, multiply num with result and make it even. reduce power 1.

        pwr = ( pwr >> 1 ) ;/// power must be even now. pwr = pwr / 2

        num = ( ( num % mod ) * ( num % mod) ) % mod; /// num ^ 2 -> num ^ 4 -> num ^ 8 ......
    }

    return ans;
}

int main()
{
    FAST;
    ll a , b , m ; /// ( a / b ) % m
    cin >> a >> b >> m ; /// input base , power , MOD

    ll b_Inv = B_Inverse( b , m - 2 , m ); ///( b ^ -1 ) = ( b ^ m-2) % m -> Euler Theorem for Prime Base (b )

    a = a % m ;/// update a

    ll ans = ( a * b_Inv) % m ; /// final Updated Answer.

    cout << ans << endl;
}

Complexity : O ( log ( MOD - 2 ) )   , 2 based log


Templete:
==========
 inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
 inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
 inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
 inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
 inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
 inline ll modInverse(ll a) { return modPow(a, MOD-2); }
 inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

