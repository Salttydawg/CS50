@echo off
echo Uploading your CS50 work to GitHub...
cd "C:\Users\tylar\OneDrive\Documents\CS50\CS50"  // Make sure this path is correct
set /p commit_msg=Enter your commit message: 
git add .
git commit -m "%commit_msg%"
git push
pause