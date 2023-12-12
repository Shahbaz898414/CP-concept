#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod=1e9+7;

int main()
{

  ll n,k,ans=1;


  cin>>n>>k;

  for(ll i=1;i<k;i++)ans=(ans*k)%mod;
	for(ll i=1;i<=n-k;i++)ans=(ans*(n-k))%mod;
	cout<<ans<<endl;


}




/*


Little penguin Polo loves his home village. The village has n houses, indexed by integers from 1 to n. Each house has a plaque containing an integer, the i-th house has a plaque containing integer pi (1 ≤ pi ≤ n).

Little penguin Polo loves walking around this village. The walk looks like that. First he stands by a house number x. Then he goes to the house whose number is written on the plaque of house x (that is, to house p[x]), then he goes to the house whose number is written on the plaque of house p[x] (that is, to house p[px]), and so on.

We know that:  

When the penguin starts walking from any house indexed from 1 to k, inclusive, he can walk to house number 1. 

When the penguin starts walking from any house indexed from k + 1 to n, inclusive, he definitely cannot walk to house number 1. 

When the penguin starts walking from house number 1, he can get back to house number 1 after some non-zero number of walks from a house to a house. 

You need to find the number of ways you may write the numbers on the houses' plaques so as to fulfill the three above described conditions. Print the remainder after dividing this number by 1000000007 (10^9 + 7).


Input
The single line contains two space-separated integers n and k (1 ≤n ≤ 1000, 1 ≤k≤min(8,n)) - the number of the houses and the
number k from the statement.

Output
In a single line print a single integer - the answer to the problem modulo 1000000007 (109 + 7).


Examples
input
5 2

output
54


*/


/*


I am enthusiastic about the Software Development Intern at MakerSharks because it aligns perfectly with my passion for cutting-edge technology and innovation. Having worked as a MERN Stack Developer intern, I've honed my skills in full-stack web development using technologies such as React.js, Node.js, Express.js, and MongoDB. The prospect of contributing to a dynamic environment where advancements in machine learning, blockchain, and FinTech are at the forefront is particularly exciting to me.

My experiences in developing responsive and user-friendly applications, coupled with my strong foundation in programming languages like C++, C, Python, and Java, position me well to tackle the challenges measured in billions, qubits, and nanoseconds at MakerSharks. I am eager to bring my technical expertise, creativity, and commitment to continuous learning to a team where innovation is not just encouraged but embraced.

Furthermore, my background in competitive programming, as evidenced by my high ratings on platforms like Codeforces and Codechef, reflects my analytical and problem-solving abilities. I believe these skills, combined with my hands-on experience and dedication to staying at the forefront of technological advancements, make me a valuable candidate for contributing to the success of MakerSharks.

I am drawn to MakerSharks not only for its global impact but also for the opportunity to be part of a forward-thinking team that is shaping the future of financial technology. I am excited about the prospect of leveraging my skills to deliver solutions that positively impact millions of customers, and I look forward to contributing to the innovative work happening within MakerSharks.

In essence, the chance to be a part of a company that values innovation and technology, while offering an environment for continuous growth, is what makes this position at MakerSharks particularly appealing to me.



*/