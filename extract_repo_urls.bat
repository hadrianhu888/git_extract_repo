#go into each directory and see if it is a git repo
#if it is, then get the url 
#save the url to a file in this current directory 
#repeat for all directories in this directory

REM Path: extract_repo_urls.bat
@go into each directory and see if it is a git repo
for /d %%i in (*) do (
    cd %%i
    if exist .git (
        git config --get remote.origin.url >> ..\repo_urls.txt
    )
    cd ..
)

#open the file and append with "git clone " to the beginning of each line
#save the file as clone_repo_urls.bat

start append_repo_url.exe 


