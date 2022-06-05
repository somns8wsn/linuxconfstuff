execute pathogen#infect()
source $VIMRUNTIME/defaults.vim

"FUNCTIONSi TOP=====
function! MyHighlights() abort
    highlight Normal      ctermbg=NONE
    highlight NonText     ctermbg=NONE
    highlight EndOfBuffer ctermbg=NONE
endfunction
"FUNCTIONS BOTTOM=====


"GROUPS TOP=====
augroup MyColors
    autocmd!
    autocmd ColorScheme * call MyHighlights()
augroup END
"GROUPS BOTTOM=====

"SIMPLE AUTOCMD'S TOP=====
autocmd VimEnter * normal! zR 
autocmd VimEnter *.py,*.gd set tabstop=4
"SIMPLE AUTOCMD'S BOTTOM=====

if v:progname =~? "evim"
  finish
endif

if has('syntax') && has('eval')
  packadd! matchit
endif

"SETTINGS TOP=====
colorscheme gruvbox
syntax on

let NERDTreeShowHidden=1
let g:indentLine_char='│'
let g:indentLine_color_term=237

set number
set background=dark
set numberwidth=5
set list lcs=tab:\│\ 
set foldenable
set foldmethod=indent
set cursorline

nnoremap ; :
vnoremap ; :
"SETTINGS BOTTOM=====
