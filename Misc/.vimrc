"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" My custom .vimrc file
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Custom Keys Mapping
"
" F1  - Vim Help - (defautl)    |
" F2  - Save Document           | Ctrl-F2  - Force save 
" F3  - Close Vim               | Ctrl-F3  - Force close (lost changes)
" F4  - Close Buffer            | Ctrl-F4  - Force close buffer (lost changes)
" F5  - Toggle highlight search 
" F6  - List Open Buffers
" F7  - 
" F8  - Open/Close Tag Bar
" F9  -
" F10 -
" F11 -
" F12 - 
"
"
"
"


execute pathogen#infect()
syntax on
filetype plugin indent on
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Files, backups and undo
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Turn backup off, since most stuff is in SVN, git et.c anyway...
set nobackup
set nowb
set noswapfile

set ai "Auto indent
set si "Smart indent

set encoding=utf-8

set tabstop=4
set shiftwidth=4
set expandtab
set path=$PWD/**

" command-line completion operates in an enhanced mode
set wildmenu
" " Show the line and column number of the cursor position
set ruler

" Ignore case when searching
set ignorecase
" " When searching, try to be smart about cases
set smartcase

highlight LineNr ctermbg=black

" Print the line number in front of each line
set number

set guicursor=n-v-c:block-Cursor
set guicursor+=i:ver100-iCursor
set guicursor+=n-v-c:blinkon0
set guicursor+=i:blinkwait10

set hidden

highlight Cursor guifg=white guibg=black
highlight iCursor guifg=white guibg=steelblue


:let mapleader = "\\"

set guifont=Liberation\ Mono\ for\ Powerline\ 10 

" Enable the list of buffers
let g:airline#extensions#tabline#enabled = 1
"
" " Show just the filename
let g:airline#extensions#tabline#fnamemod = ':t'"

" Need this for the terminator
let &t_Co=256

let g:airline_left_sep='>'

let g:airline_theme="solarized"

let g:airline_powerline_fonts = 1

" Move to the next buffer
nmap <M-Right> :bnext<CR>
"
" " Move to the previous buffer
nmap <M-Left> :bprevious<CR>"


"""""""""""""""""""""""""""""""""""""""
" Search
"""""""""""""""""""""""""""""""""""""""

" Open vim grep in the palce to type the string to find, looks only in cpp and
" h files
" map <C-h>c :vimgrep // **/*.cpp **/*.h<left><left><left><left><left><left><left><left><left><left><left><left><left><left><left><left><left> 

" Same as above but look in all files
" map <C-h>a :vimgrep // **/*.*<left><left><left><left><left><left><left><left>



" To find a file in the subdirectories, need the file full name to work
map <C-f> :find<Space>

" Toggle highlight search on/off. Press * over a word to search it
noremap <F5> :set hlsearch! hlsearch?<CR>

" Open the file tree exploer
map <C-n> :NERDTreeToggle<CR>

" Search
map <space> /

" Back search
map <c-space> ?

""""""""""""""""""""""""""""""""""""""
" Window manipulation
"""""""""""""""""""""""""""""""""""""""

" Change the current open buffer window
map <Tab> <C-W>w

"""""""""""""""""""""""""""""""""""""
" File editor helper
""""""""""""""""""""""""""""""""""""""
map <M-Up> :m -2<CR>==
map <M-Down> :m +1<CR>==
nnoremap    <C-u>    :UndotreeToggle<cr> 


""""""""""""""""""""""""""""""""""""
" Tags and project navigation
"""""""""""""""""""""""""""""""""""

" Open file tags list
nmap <F8> :TagbarToggle<CR>

" List all calls or callers to the selected word
nnoremap <C-\> :call CscopeFindInteractive(expand('<cword>'))<CR>

" nnoremap <leader>l :call ToggleLocationList()<CR>

"""""""""""""""""""""""""""""""""""
" Buffer manipulation
"""""""""""""""""""""""""""""""""""
nnoremap <F6> :buffers<CR>:buffer<Space>

" copy all to clipboard
map<C-S-a> :%y+<CR>

" Save with F2
nnoremap <F2> :w<CR>zz
inoremap <F2> <Esc><F2>i

nnoremap <C-F2> :w!<CR>zz
inoremap <C-F2> <Esc><C-F2>i

" Close vim with F3
nnoremap <F3> :q<CR>
inoremap <F3> <Esc><F3>i

nnoremap <C-F3> :q!<CR>
inoremap <C-F3> <Esc><C-F3>i

"Close a buffer with F4

nnoremap <F4> :bd<CR>
nnoremap <C-F4> :bd!<CR>

"map<F9> :execute ':GrepList //<left>' | echo "po"

map<C-h>c :call GrepCpp() <CR>
map<C-h>a :call GrepAll() <CR>

function! GrepCpp()
    let filter = input("Search in .cpp and .h files in project: ")
    execute "vimgrep /" . filter . "/gj **/*.cpp **/*.h"
    execute "cw"
endfunction

function! GrepAll()
    let filter = input("Search in all project files': ")
    execute "vimgrep /" . filter . "/gj **/*"
    execute "cw"
endfunction

if !exists('g:airline_symbols')
    let g:airline_symbols = {}
endif

" unicode symbols
let g:airline_left_sep = '»'
let g:airline_left_sep = '▶'
let g:airline_right_sep = '«'
let g:airline_right_sep = '◀'
let g:airline_symbols.linenr = '␊'
let g:airline_symbols.linenr = '␤'
let g:airline_symbols.linenr = '¶'
let g:airline_symbols.branch = '⎇'
let g:airline_symbols.paste = 'ρ'
let g:airline_symbols.paste = 'Þ'
let g:airline_symbols.paste = '∥'
let g:airline_symbols.whitespace = 'Ξ'



