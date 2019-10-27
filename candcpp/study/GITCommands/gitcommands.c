Git commands:

git clone repositoryUrl
git clone https://github.com/Rajanarender/Selfstudy.git
git checkout -b branchName //to create and checkout branch
#if 0
git branch branchName //to create branch
git branch -d branchName //to delete branch
git checkout branchName //to checkout branch
#endif
git blame filename //to see the changes made by each user in that file

git init
git add filename
git commit -m "File added newly"
git log //to get the list of all commit id's
git status //to see the status of files[whether saved(green color),unsaved(red color)]
git push origin branchName
git pull origin branchName
git rebase branchname //Rebase current branch onto another branch
git revert //To undo the changes made by the commit
git reset --hard //To undo the changes, getting back the old file
git stash //To save a file
git stash list //To see all saved files
git diff //shows unsaved files
git cherry-pick filename //To move the commitid to other branch
git fetch -all //To get all repositories from git to local
