#!/bin/bash
# Go into each directory and check if it is a git repository
# If it is, then extract the remote url and print it out
# If it is not, then print out the directory name
# If it is, then save the remote url to a file in the current working directory
# Name the file git_repos_url.txt and save it in the current working directory
# Open the file and append before each url with "git clone "
# This will allow you to copy and paste the urls into the terminal to clone the repositories
# This script is useful if you have a lot of git repositories and you want to clone them all
# This script is useful if you want to clone all the repositories from a directory
# Rename the file to git_clone_repo_urls.sh and make it executable
# Usage: extract_repos_url.sh <directory>
# Check if the user has provided a directory
if [ $# -eq 0 ]; then
	echo "Usage: extract_repos_url.sh <directory>"
	exit 1
fi
# Check if the directory exists
if [ ! -d $1 ]; then
	echo "Directory does not exist"
	exit 1
fi
# Go into the directory
cd $1
# Check if the file exists
if [ -f git_repos_url.txt ]; then
	rm git_repos_url.txt
fi
# Create the file
touch git_repos_url.txt
# Loop through each directory
for dir in $(ls -d */); do
	# Go into the directory
	cd $dir
	# Check if it is a git repository
	if [ -d .git ]; then
		# Extract the remote url
		git remote -v | grep fetch | awk '{print $2}' >>../git_repos_url.txt
	else
		# Print out the directory name
		echo $dir >>../git_repos_url.txt
	fi
	# Go back to the parent directory
	cd ..
done
# Open the file
vim git_repos_url.txt
# Append before each url with "git clone "
sed -i 's/^/git clone /' git_repos_url.txt
# Print out the file
cat git_repos_url.txt
# rename the file to git_clone_repo_urls.sh
mv git_repos_url.txt git_clone_repo_urls.sh
# make the file executable
chmod +x git_clone_repo_urls.sh
# close the file
exit
