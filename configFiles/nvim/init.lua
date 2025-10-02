print("lmao")

vim.wo.number = true
vim.wo.rnu = true
vim.opt.tabstop=4
vim.opt.shiftwidth=4
vim.opt.expandtab = true

local keymap = vim.api.nvim_set_keymap

local Plug = vim.fn['plug#']

vim.call('plug#begin')
Plug 'mattn/emmet-vim'
Plug 'preservim/nerdtree'
Plug 'andweeb/presence.nvim'
Plug 'williamboman/mason.nvim'
Plug 'neovim/nvim-lspconfig'
Plug 'nvim-treesitter/nvim-treesitter'

--autocomps
Plug 'hrsh7th/nvim-cmp'
Plug 'hrsh7th/cmp-nvim-lsp'
Plug 'hrsh7th/cmp-buffer'
Plug 'hrsh7th/cmp-path'

--Snippets
Plug 'L3MON4D3/LuaSnip'
Plug 'saadparwaiz1/cmp_luasnip'

vim.call('plug#end')

require("mason").setup()


vim.lsp.enable('omnisharp')
vim.lsp.enable('html')
vim.lsp.enable('cssls')
vim.lsp.enable('eslint')
vim.lsp.enable('bashls')
vim.lsp.enable('jsonls')
vim.lsp.enable('pylsp')

require'nvim-treesitter.configs'.setup {
    ensure_installed = {"c_sharp","html","css","scss","javascript","typescript","razor","json","xml","python"},

    highlight = {
        enable = true,
        additional_vim_regex_highlighting = false,
    },
}

vim.diagnostic.config({
    virtual_text = true,
    signs = true,
    underline = true,
    update_in_insert = false,
})


local cmp = require("cmp")
local luasnip = require("luasnip")

cmp.setup({
  snippet = {
    expand = function(args)
      luasnip.lsp_expand(args.body)
    end,
  },
  mapping = {
    ["<Up>"] = cmp.mapping.select_prev_item(),
    ["<Down>"] = cmp.mapping.select_next_item(),
    ["<CR>"] = cmp.mapping.confirm({ select = true }),
    ["<C-Space>"] = cmp.mapping.complete(),
    ["<C-e>"] = cmp.mapping.close(),
  },
  sources = cmp.config.sources({
    { name = "nvim_lsp" },
    { name = "buffer" },
    { name = "path" },
    { name = "luasnip" },
  })
})

keymap('n', '<S-l>', '<Cmd>update | !pdflatex -interaction=batchmode main.tex<CR>', {noremap = true})
keymap('n', '<S-m>', '<Cmd>update | !make<CR>', {noremap = true})
keymap('n', '<S-t>', '<Cmd>NERDTreeToggle<CR>', {noremap = true})
keymap('n', '<S-Left>', '<Cmd>NERDTreeFocus<CR>', {noremap = true})
keymap('n', '<S-Right>', '<Cmd>wincmd w<CR>', {noremap = true})
