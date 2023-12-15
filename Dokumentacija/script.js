let ExpandButton = document.getElementById("expand-button-super");
let SidePanel = document.getElementById("navbar");
let Main = document.getElementById("main");
let isOpen = true;

function ExpandMenu()
{   
    if(isOpen == false)
    {
        isOpen = true;
        SidePanel.classList.toggle("side-nav-bar-closed");
        SidePanel.classList.toggle("side-nav-bar");

        Main.classList.toggle("main-changed");
        Main.classList.toggle("main");
        return;
    }
}

function CloseMenu()
{
    if(isOpen == true)
    {
        isOpen = false;
        SidePanel.classList.toggle("side-nav-bar");
        SidePanel.classList.toggle("side-nav-bar-closed");

        Main.classList.toggle("main");
        Main.classList.toggle("main-changed");
        return;
    }
}

ExpandButton.addEventListener("click", function()
{
    if(isOpen == true)
    {
        isOpen = false;
        SidePanel.classList.toggle("side-nav-bar");
        SidePanel.classList.toggle("side-nav-bar-closed");

        Main.classList.toggle("main");
        Main.classList.toggle("main-changed");
        return;
    }
    if(isOpen == false)
    {
        isOpen = true;
        SidePanel.classList.toggle("side-nav-bar-closed");
        SidePanel.classList.toggle("side-nav-bar");

        Main.classList.toggle("main-changed");
        Main.classList.toggle("main");
        return;
    }
})

document.addEventListener('keydown', function(event) {

    if (event.shiftKey && event.key === 'ArrowLeft') {
        CloseMenu();
    }

    if (event.shiftKey && event.key === 'ArrowRight') {
        ExpandMenu();
    }
});