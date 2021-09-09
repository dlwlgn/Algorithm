# 계단 오르기

## 문제 링크
https://www.acmicpc.net/problem/

## 풀이 방법
DFS & Memoization
or
DP

## 간단한 풀이 설명
DFS로 완전 탐색을 시킨다.<br>
그러나 시간 초과를 방지하기 위해 memoization을 사용해서 같은 스택, 층일때 이전에 더 큰 값 기록이 존재할 경우 return을 시켜준다.<br>
DFS memoization은 DP와 본질적으로 동일하다.<br>

## 실수했던 부분
처음엔 memoization없이 해서 시간초과가 났다.<br>
두번째는 memoization을 스택을 반영하지 않아서 실패가 났다.<br>
세번째에 memoization에 층, 스택을 모두 반영하자 성공이 났다.<br>