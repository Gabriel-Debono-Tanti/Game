## Code

Contributing and adding your code is actually pretty easy, since we use Github for our project.
Getting an account is a must if you want to contribute to [This project](https://github.com/Gabriel-Debono-Tanti/Game/).

### Setting Up

#### Console 
1. Fork  [This project](https://github.com/Gabriel-Debono-Tanti/Game/) so you have a personal repository to push to.

2. Clone your personal repository with `git clone --recursive https://github.com/YOUR-USERNAME/Game`. Remember to change the URL to your repository. The --recursive is used to download the third party libraries for building.

3. Move into the directory, on Linux this is done with `cd Game`.

4. Follow the instructions to create a build and make sure your local copy is working.

Add an upstream remote so you can get other developers' updates with `git remote add upstream https://github.com/Gabriel-Debono-Tanti/Game`.

#### Github Desktop

1. Go to the top-left of https://github.com/Gabriel-Debono-Tanti/Game 
2. Fork the project and go to your profile
3. Go to the forked repository and under code press Open with Github Desktop then set a location for it.


### Updating Repository (Console)

These instructions will update both your local repository and online fork:

1. `git fetch upstream` Will download any new changes from this repository.

2. `git checkout master` Will switch to your master branch.

3. `git merge upstream/master` Will merge or fast-forward your local master branch so it contains all the updates.

4. `git push origin master` Will update your online repository's master branch, it's a good idea to keep it up to date.

### Making Changes

So you have added a feature or fixed some bugs which were found by you, good job! You can now contribute to the master project. In that case you will need to create a feature branch.
This means that you will add your code to the master project and ensure that the master branch is working fine. With that said you might need to add comments in your code a clear title or a description on what you have found / created
so developers will know what you've been up to. This can be done by commenting or creating an issue or pull request here: https://github.com/Gabriel-Debono-Tanti/Game/pulls.





## Github Desktop

1. Publish the branch and commit to your fork.
2. Go to https://github.com/LibreSprite/Dotto/pulls and create a new pull request.
3. Give a detailed title and description of your changes so that developers will know what you changed.
4. Wait for a response.
5. If you are asked to change something, change it and repeat step 1.


### Libraries Needed:

#### SFML

Since our project works on sfml it is a necessity to set it up.
You can check out on how to build it for your OS [Here](https://www.sfml-dev.org/tutorials/2.5/)

##### Integration
Now to integrate it you will need to create two folders in 'Game/src' and call them 'lib' and 'include'
In lib you would need to put in the libraries which you built.
In 'include' you would need to create a folder called 'SFML' and put all the headerfiles in it.
Then you would need to configure the Makefile to work with your compiler.
(Do note you should just create a seperate project before you start)




