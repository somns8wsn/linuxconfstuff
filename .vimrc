execute pathogen#infect()

if v:progname =~? "evim"
  finish
endif

" Get the defaults that most users want.
source $VIMRUNTIME/defaults.vim

"if &t_Co > 2 || has("gui_running")
"  " Switch on highlighting the last used search pattern.
"  set hlsearch
"endif

if has('syntax') && has('eval')
  packadd! matchit
endif

function! MyHighlights() abort
    highlight Normal      ctermbg=NONE
    highlight NonText     ctermbg=NONE
    highlight EndOfBuffer ctermbg=NONE
endfunction

augroup MyColors
    autocmd!
    autocmd ColorScheme * call MyHighlights()
augroup END

colorscheme gruvbox
syntax on

let NERDTreeShowHidden=1
let g:indentLine_char='│'
let g:indentLine_color_term=237

set number
set background=dark
set tabstop=4
set numberwidth=5
set list lcs=tab:\│\ 
