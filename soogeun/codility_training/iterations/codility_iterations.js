// https://app.codility.com/programmers/lessons/1-iterations/
// Codility 예제 - iterations
// 풀이 링크: https://app.codility.com/demo/results/trainingHJJEVB-9RH/

// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(N) {

    // N -> Binary Number String
    const binaryString = convertNumToBinaryString(N);

    // for loop
    // 0 시작, 1 만나기 전까지 count -> 1 만나면 count를 array에 저장 후 0으로 초기화
    let count = 0;
    const binaryGaps = [];

    for (i = 0; i < binaryString.length; i++) {
        if ( binaryString[i] === '0' ) {
            count += 1;
        }
        else {
            if (count > 0) {
                binaryGaps.push(count);
                count = 0;
            }
        }
    }

    binaryGaps.sort((a, b) => b - a);

    return binaryGaps[0] ? binaryGaps[0] : 0;
}

function convertNumToBinaryString (num) {
    /**
     * num이 정수 형태임을 확인
     * 구현 X
     */

    let binaryString = "";

    while (num > 0) {
        const cur = num % 2;
        binaryString = cur + binaryString;
        num = num >> 1;
    }

    return binaryString;
}
