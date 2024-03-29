# [Platinum V] 순열 뒤집기 - 25503 

[문제 링크](https://www.acmicpc.net/problem/25503) 

### 성능 요약

메모리: 5728 KB, 시간: 36 ms

### 분류

애드 혹(ad_hoc), 자료 구조(data_structures), 스택(stack)

### 문제 설명

<p>순열 $ P $가 주어질 때, 아래 방식으로 $ P $를 정렬할 수 있는지 판별해보자.</p>

<ol>
	<li>올바른 괄호 문자열 $ S $를 만든다.</li>
	<li>$ S $의 중간중간에 $ P $의 원소들을 순서대로 넣는다. $ S $의 맨 앞이나 맨 뒤에도 원소를 넣을 수 있다.</li>
	<li>각 괄호 짝에 대해서, 그 안에 있는 원소들의 순서를 뒤집은 뒤, 괄호 짝을 지운다.
	<ul>
		<li>만약 어떤 괄호 짝 안에 다른 괄호 짝이 있다면, 안쪽에 있는 괄호 짝을 먼저 처리한다.</li>
	</ul>
	</li>
</ol>

<p>문제에서 등장한 용어를 모른다면, 아래 정의를 읽어보자.</p>

<ul>
	<li><strong>순열</strong>이란 $ 1 $부터 $ N $까지의 정수가 1번씩 등장하는 길이 $ N $의 수열을 의미한다.</li>
	<li><strong>올바른 괄호 문자열</strong>은 아래와 같이 재귀적으로 정의된다.
	<ul>
		<li>빈 문자열은 올바른 괄호 문자열이다.</li>
		<li>두 올바른 괄호 문자열을 이어붙인 문자열은 올바른 괄호 문자열이다.</li>
		<li>올바른 괄호 문자열을 괄호로 감싼 문자열은 올바른 괄호 문자열이다.</li>
	</ul>
	</li>
</ul>

### 입력 

 <p>첫째 줄에는 순열의 길이 $ N $이 주어진다. ($ 1 \leq N \leq 300\,000 $)</p>

<p>둘째 줄에는 순열 $ P $의 원소가 공백을 사이에 두고 주어진다.</p>

### 출력 

 <p>순열을 정렬할 수 있으면 <code>YES</code>를,  아니면 <code>NO</code>를 출력한다.</p>

