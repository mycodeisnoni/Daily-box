const arr = [4,3,5,1,6,5];
let cnt = 0;

arr.forEach((element) => {
    if(element%2===1){
        cnt++;
    }
})
console.log(cnt)

// foreach의 