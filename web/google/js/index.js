// toggle-button 클릭 시에 이벤트 발생

const toggleButton = document.querySelector(".toggle-button");
const body = document.querySelector("body");
const headerNav = document.querySelector('.haeder-nav')
const bookmarkWrapper = document.querySelector('.bookmark-wrapper')
const text = document.querySelectorAll('.text')

toggleButton.addEventListener('click',function(){
    console.log("다크모드 버튼이 눌렸어요!!")

    // 버튼 클릭마다 클래스리스트에 토글로 클래스 추가
    toggleButton.textContent = "다크모드"
    toggleButton.classList.toggle("toggle-button-darkmode");
    body.classList.toggle("body-bg-darkmode")

    headerNav.classList.toggle("text-darkmode")

    // bookmarkWrapper.classList.toggle("text-darkmode")

    for(let i = 0; i < text.length ; i++){
        texts[i].classList.toggle('text-darkmode')
    }

    if(toggleButton.classList.contains("toggle-button-darkmode")){
        toggleButton.textContent = "일반 모드";
    }

})


// 구글 이동
const searchInput = document.querySelector(".search-input")
searchInput.addEventListener('keyup',function(e){
    console.log(e)
    // e.code === enter : 
    if(e.code === "Enter"){
        console.log("가즈아!")

        if(!e.target.value){
            alert("검색어를 입력하지 않았습니다!")
            return;
        }

        const target = "https://www.google.com/search?q="
        // 이동하는 두가지 방법

        // 첫 번째 그냥 이동
        // location.href
        // location.href = target + a.target.value;

        // 새탭이동
        // window.open
        window.open(target + e.target.value)
    }
})