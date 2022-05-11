// Codility Training - Time Complexity 1 (FrogJmp)
// 문제 링크: https://app.codility.com/programmers/lessons/3-time_complexity/
// Solution Link 1: https://app.codility.com/demo/results/trainingEATSY4-GHH/ -> 88%  pass
// Solution Link 2: https://app.codility.com/demo/results/training6ZCMQU-W5F/ -> 100% pass

function solution(X, Y, D) {
    const distance = Y - X;
    const minJumps = distance % D === 0 
        ? Math.trunc(distance / D)          // parseInt(distance / D)
        : Math.trunc(distance / D) + 1;     // parseInt(distance / D) + 1

    return minJumps;
}