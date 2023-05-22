function sleep(delay){
    const start = Date.now();  // Date.now() = 현재시간
    let limit = start + delay;
    while(Date.now()<limit){}
}

console.log("빨래")
sleep(3000)
console.log("설거지")
// 동기적 코드 : 빨래 하고 3초는 지나야 설거지