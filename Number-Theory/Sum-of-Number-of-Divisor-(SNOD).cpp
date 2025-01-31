Method-1:
==========
Sum of Number of Divisor  কে Divisor Summatory Function বলা হয়। একটি সংখ্যা N দেওয়া থাকবে। ১ থেকে N পর্যন্ত সব গুলোর NOD বের করে সাথে সাথে যোগ করতে হবে। 

SNOD ( N ) = ∑ NOD ( i ) Here, Lower Limit, i = 1 and Upper Limit i = N;

অর্থ্যাৎ ১ থেকে N পর্যন্ত লুপ চালিয়ে NOD ( i ) বের করে যোগ করলেই SNOD ( N ) বের হয়ে যাবে। এক্ষেত্রে Complexity = O ( Loop x NOD ) = O [ N x { sqrt(N) / ln ( N ) } ].
  
Method-2:
=========
  
SNOD ( 10 ) = NOD ( 1 ) + NOD ( 2 ) + ------- + NOD ( 10 )
  
  NOD ( 1 ) = 1               = 1
  NOD ( 2 ) = 1 , 2           = 2
  NOD ( 3 ) = 1 , 3           = 2
  NOD ( 4 ) = 1 , 2 , 4       = 3
  .
  .
  .
  NOD ( 10 ) = 1 , 2 , 5 , 10 = 4
----------------------------------------------
  SNOD ( 10 )                 = 27
  
এখানে ১ সব সংখ্যাকে ভাগ করে। ১ দ্বারা বিভাজ্য সংখ্যা = ১০ / ১ = ১০ টা
                             ২ "    "      "   = ১০ / ২ = ৫ টা
                             ৩ "    "      "   = ১০ / ৩ = ৩ টা
                             .
                             .
                             .
                             ১০ "   "       "  = ১০ / ১০ = ১ টা
  -------------------------------------------------------------------
                          SNOD ( 10 )                     = ২৭
                          
১ থেকে N পর্যন্ত লুপ চালিয়ে সহজে SNOD ( N ) বের করা যায়। 
SNOD ( N ) = ( N / 1 ) + ( N / 2 ) + ( N / 3 ) + ----------------- + ( N / N ) =  ∑ NOD ( N / i ) Here, Lower Limit, i = 1 and Upper Limit i = N;
  
Complexity: O ( Loop ) = O ( N ).

  
Method-3
============
Divisor Pair : কোন সংখ্যা A এর একটি ডিভাইজর ২ হলে ( A / ২ ) হবে অপর একটি ডিভাই্জর । এটিই ডিভাইজর পেয়ার।যেমন, ( 2 , 10/2 ) = ( 2 , 5 ) হচ্ছে ১০ এর একটা Divisor Pair.

1 থেকে 10 পর্যন্ত সব সংখ্যার Divisor Pair :

DPair ( 1 ) = ( 1 , 1 )                                     = 1
DPair ( 2 ) = ( 1 , 2 ) , ( 2 , 1 )                         = 2
DPair ( 3 ) = ( 1 , 3 ) , ( 3 , 1 )                         = 2
DPair ( 4 ) = ( 1 , 4 ) , ( 2 , 2 ) , ( 4 , 1 )             = 3
.
.
.
DPair ( 10 ) = ( 1 , 10 ) , ( 2 , 5 ) , ( 5 , 2 ) ( 10 , 1 ) = 4
---------------------------------------------------------------------------
Total DPair ( 10 ) = SNOD ( 10 )                            = 27
  
১ থেকে ১০ পর্যন্ত সব সংখ্যার প্রত্যে্কটিকে n ধরলে সংখ্যাগুলো আছে  ( a x b ) = n আকারে। যারা a < b or a == b or a > b এই ভাবে জোরা গঠন করে।

তাই ( a < b ) , ( a > b ) , ( a == b ) এর মান বের করার মাধ্যমে উত্তর বের করে ফেলতে পারি।

এখানে a বের করে ফেলতে পারলে n/a = b বের করে ফেলতে পারবো। a যেহেতু n এর ছোট ডিভাইজর তাই a হবে সর্বোচ্চ sqrt ( n ). তা না হলে ( a x b ) > n পাওয়া যাবে।
সুতরাং a থেকে sqrt ( n ) পর্যন্ত লুপ চালিয়ে যখন ( n % i == 0 ) পাবো তখন a =  i এবং b = n / i = n / a । এভাবে সকল ডিভাইজর পেয়ার বের করে ফেলতে পারি।    

এখন, আমরা শুধু সেই সব পেয়ার নিবো যেখানে, a < b হবে। যেমন, 
১০ এর ক্ষেত্রে sqrt(10) = ৩, প্রথমে আসবে  ১ অর্থ্যাত ১ থেকে ১০ পর্যন্ত কতগুলো সংখ্যা আছে যেগুলো ১ দ্বারা নিঃশেষে বিভাজ্য এবং ( 1 < b ) হবে। same for 2 , 3.
২ এর জন্য উত্তর,
( ২ , ১ ) = ২ , ( ২ , ২ ) = ৪ , ( ২ , ৩ ) = ৬ , ( ২ , ৪ ) = ৮ , ( ২ , ৫ ) = ১০ অর্থ্যাৎ ( ১ , ২ , ৩ , ৪ , ৫ ) হচ্ছে ২ এর সাথে ডিভাইজর পেয়ার। কিন্তু ১ , ২ দুই এর বড় না হওয়ায়
( 2 < b ) শর্ত পূরণ হবে না । তাই ( ৩ , ৪ , ৫ ) কে শুধু ব্যাবহার করবো শর্ত পূরণের জন্য। 

এখানে কতগুলো সংখ্যা আছে যেগুলো শর্ত ( 2 < b ) পূরণ করবে ?
উত্তরঃ ( ১০ / ২ ) - ২ = ( ৫ - ২ ) = ৩ টি সংখ্যা। সেগুলো হচ্ছেঃ ৩ , ৪ , ৫ --> ( ২ , ৩ ) = ৬ , ( ২ , ৪ ) = ৮ , ( ২ , ৫ ) = ১০ যেখানে ( ২ < b )
Formula : { ( N / a ) - a } 

সুতরাং এই মেথড কাজে লাগিয়ে Divisor Pair থেকে বের করতে হবে ১ থেকে ১০ পর্যন্ত কতগুলো সংখ্যা আছে যেখানে ( a < b ) , ১ থেকে sqrt(10) পর্যন্ত লুপ চালিয়ে,
ans = [ 10 / 1 ] - 1     +     [ 10 / 2 ] - 2     +     [ 10 / 3 ] - 3     + ----------- +      [ 10 / sqrt(10) ] - sqrt(10)
  
আবার, Divisor Pairt বের করতে হবে ১ থেকে ১০ পর্যন্ত কতগুলো সংখ্যা আছে যেখানে ( a > b )
ans = Total ( a > b ) = Total ( a < b ). অর্থাৎ আমরা যদি ( 2 , 4 ) পাই ডিভাইজর পেয়ার এ তাহলে অবশ্যই ( 4 , 2 ) পাবো ডিভাইজর পেয়ার এ।
এখানে, ( a < b ) এর মান পূর্বেই বের করা হয়েছে। তাই ( a > b ) এর মান হবে ( a < b ) এর মানের সমান।

এবং ( a == b ) এর ক্ষেত্রে , 
( a == b ) পাওয়া যাবে যদি সংখ্যাটি Perfect Square  ( ১, ৪ , ৯ , ১৬ , ---- , PS ) হয়। যেমন, 4 x 4 = 16 , 5 x 5 = 25 ইত্যাদি। 
answer = total Perfect Square, for  ( a == b ).
  
 Final Answer = Total ( a < b ) + Total ( a > b ) + Total ( a == b ) = 12 + 12 + 3 = 27
              = 2 x Total ( a < b ) + Perfect Square = 2 x 12 + 3 = 27
              = ( 2 x ∑ ( ( N / i ) - i) , lim 1 to sqrt(N) ) + Perfect Square = 2 x 12 + 3 = 27 
  
Code :
=======
int SNOD ( int n )
{
    int lim = floor(sqrt(n));/// loop 1 to sqrt ( n ) 

   int ans = 0; /// Store total num who are ( a < b ) =  ( ∑ ( ( N / i ) - i) , lim 1 to sqrt(N) )
    int ps = 0; /// Calculate total Perfect Square 
    for(int i = 1; i <= lim; i++)
    {
        if ( i * i <= n) ps++ ; /// Check Perfect Square smaller than n

        ans = ans + ( ( n / i ) - i ) ; /// Formula :  ( N / a ) - a for calculate Total ( a < b ).
    }

    ans = ( 2 * ans ) ; /// Total ( a < b ) = Total ( a > b ). 

    ans = ( ans + ps ) ; /// Add Perfect Square in answer.

    return ans;/// SNOD = ( 2 x ∑ ( ( N / i ) - i) , lim 1 to sqrt(N) ) + Perfect Square
}

int main()
{
    FAST;
    int n = 10;

    cout << SNOD( n ) << endl;
}

Complexity : O ( Sqrt (N) ) /// Just a loop 1 to sqrt(N)
