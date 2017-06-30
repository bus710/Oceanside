
[Back to main](../README.md#server)



# https://www.joinc.co.kr/w/man/12/golang/Start

# ----------------------------------
# 1. install golang itself.
# newer version can be found golang's official web site.
sudo apt-get install -y golang

# ----------------------------------
# 2. install pathogen.
mkdir -p ~/.vim/autoload ~/.vim/bundle
cd ~/.vim/autoload
curl -LSso pathogen.vim https://tpo.pe/pathogen.vim

# add lines to .vimrc
execute pathogen#infect()
syntax on
filetype plugin indent on

# ----------------------------------
# 3. install vim-go
cd ~/.vim/bundle
git clone https://github.com/fatih/vim-go.git

# add line to .profile
export GOPATH=$HOME/golang
export PATH=$PATH:$GOPATH/bin

# run below commands in terminal
source ~/.profile
mkdir $HOME/golang

# open vim and run below command
# :GoInstallBinaries

# ----------------------------------
# 4. install YouCompleteMe
# this requires python-dev and cmake
cd ~/.vim/bundle
git clone https://github.com/Valloric/YouCompleteMe.git
cd YouCompleteMe
git submodule --init --recursive
./install.sh
./install.py --gocode-completer (or --all)

# ----------------------------------
# 5. install Tagbar
sudo apt-get install ctags
cd ~/.vim/bundle
git clone https://github.com/majutsushi/tagbar.git

# add lines to vimrc
nmap <F8> :TagbarToggle<CR>

# ----------------------------------
# 6. install nerdtree
cd ~/.vim/bundle
git clone https://github.com/scrooloose/nerdtree.git

# add lines to vimrc
nmap <C-n> :NERDTreeToggle<CR>

