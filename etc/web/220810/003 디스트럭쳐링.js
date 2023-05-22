// Destructuring (구조분해할당)

const obj ={
    name : "허범성",
    job : "강사",
    belong : "싸피"
}

console.log(obj.name)
console.log(obj['name'])


// 아래처럼 쓰게되면 메모리 낭비
//const name = obj.name;
//const job = obj.job;
//const belong = obj.belong;

// 대괄호 안에 들어가게 되면 객체 안에 있다는 뜻.
const { name } = obj;
const { job } = obj;
const { belong } = obj;