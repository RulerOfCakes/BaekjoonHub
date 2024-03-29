# [Platinum III] functionx - 25317 

[문제 링크](https://www.acmicpc.net/problem/25317) 

### 성능 요약

메모리: 38144 KB, 시간: 356 ms

### 분류

많은 조건 분기(case_work), 값 / 좌표 압축(coordinate_compression), 자료 구조(data_structures), 세그먼트 트리(segtree)

### 문제 설명

<p>$x$를 변수로 하는 다항식 $f(x)$가 있다. 처음에 $f(x) =1$이다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.</p>

<ul>
	<li>$1$ $a$ $b$: $f(x)$에 $(ax+b)$를 곱한다.</li>
	<li>$2$ $c$: $f(c)$가 음수라면 <span style="color:#e74c3c;"><code>-</code></span>, $0$이라면 <span style="color:#e74c3c;"><code>0</code></span>, 양수라면 <span style="color:#e74c3c;"><code>+</code></span>를 출력한다.</li>
</ul>

### 입력 

 <p>첫 번째 줄에 쿼리의 개수 $Q$가 주어진다. $(1\leq Q\leq 200\, 000)$</p>

<p>다음 $Q$개의 줄에는 쿼리가 문제에서 언급한 형식으로 한 줄에 하나씩 주어진다. 2번 쿼리는 하나 이상 주어진다. $(-10^{18}\leq a,b,c\leq 10^{18}$; $a$, $b$, $c$는 정수$)$</p>

### 출력 

 <p>$2$번 쿼리가 주어질 때마다 정답을 한 줄에 하나씩 출력한다.</p>

