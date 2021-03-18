"For syntax highlighting.
syntax on

"To show line mumbers.
set number

"For autoindentation of braces.
set autoindent
inoremap { {}<left>
inoremap {<CR> {<CR>}<ESC>O
inoremap {;<CR> {<CR>};<ESC>O

"Search highlighting enabled when searching for words or phrases.
set hlsearch

"Smooth scroll enabled with mouse.
function SmoothScroll(up)
    if a:up
        let scrollaction=""
    else
        let scrollaction=""
    endif
    exec "normal " . scrollaction
    redraw
    let counter=1
    while counter<&scroll
        let counter+=1
        sleep 10m
        redraw
        exec "normal " . scrollaction
    endwhile
endfunction

nnoremap <C-U> :call SmoothScroll(1)<Enter>
nnoremap <C-D> :call SmoothScroll(0)<Enter>
inoremap <C-U> <Esc>:call SmoothScroll(1)<Enter>i
inoremap <C-D> <Esc>:call SmoothScroll(0)<Enter>i

"Hit Tab to indent 4 spaces.
filetype plugin indent on
" show existing tab with 4 spaces width
set tabstop=4
" when indenting with '>', use 4 spaces width
set shiftwidth=4
" On pressing tab, insert 4 spaces
set expandtab

" Default starting code when creating a new file of cpp type
autocmd FileType cpp call IoStream()
fu! IoStream()
    if line("$") == 1
        call append(0, "#include <iostream>")
        call append(1, "#include <algorithm>")
        call append(2, "#include <cmath>")
        call append(3, "#include <climits>")
        call append(4, "using namespace std;")
        call append(5, "")
        call append(6, "int main(){")
        call append(7, "")
        call append(8, "    return 0;")
        call append(9, "}")
    endif
endfu
