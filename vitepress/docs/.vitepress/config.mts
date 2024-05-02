import { defineConfig } from 'vitepress'
import markdownItKatex from 'markdown-it-katex'
// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "shubulan's algorithm route",
  description: "algorithm template",
  base: "/Algorithm_Essentials/vitepress/",
  markdown: {
    config: (md) => {
      md.use(markdownItKatex)
    }
  },
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: '知识点', link: '/contents/' },
      { text: '面试通关', link: '/interview/' }
    ],

    sidebar: {
      '/contents/': [
        {
          text: '基本介绍',
          collapsed: true,
          items: [
            { text: '项目介绍', link: '/contents/index' },
            { text: '算法初步介绍', link: '/contents/introduction' },
          ]
        },
        {
          text: '穷竭枚举',
          collapsed: true,
          items: [
            { text: '循环枚举', link: '/contents/ch00/for_while_loop' },
            { text: '深度优先：递归与回溯', link: '/contents/ch00/dfs' },
            { text: '指数型枚举', link: '/contents/ch00/exponential_enumeration'},
            { text: '组合型枚举', link: '/contents/ch00/combinatorial_enumeration'},
            { text: '排列型枚举', link: '/contents/ch00/permutation_enumeration'},
            { text: '广度优先：无权图的最短路', link: '/contents/ch00/bfs'},
          ]
        },
        {
          text: '基本算法',
          collapsed: true,
          items: [
            { text: '排序算法', link: '/contents/ch01/sort' },
            { text: '递归与分治', link: '/contents/ch01/binary_search' },
            { text: '二分算法', link: '/contents/ch01/binary_search' },
          ]
        },
        {
          text: '常用技巧与代码能力提升',
          collapsed: true,
          items: [
            { text: '前缀和与差分', link: '/contents/ch02/presum_diff' },
            { text: '思维题', link: '/contents/ch02/think_problem' },
            { text: '双指针', link: '/contents/ch02/two_pointer' },
            { text: '位运算', link: '/contents/ch02/bitwise_operation' },
            { text: '模拟', link: '/contents/ch02/' },
            { text: '构造', link: '/contents/ch02/' },
          ]
        },
        {
          text: '数据结构',
          collapsed: true,
          items: [
            { text: '简单数据结构', link: '/contents/ch03/data_structure_I' },
            { text: '单调栈与单调队列', link: '/contents/ch03/monotonic_queue_stack' },
          ]
        },
        {
          text: '搜索技巧与图论',
          collapsed: true,
          items: [
            { text: '最短路径', link: '/contents/ch04/README' },
          ]
        },
        {
          text: '数学',
          collapsed: true,
          items: [
            { text: '基本数学问题', link: '/contents/ch05/README' },
          ]
        },
        {
          text: '动态规划',
          collapsed: true,
          items: [
            { text: '状压dp', link: '/contents/ch06/bitwise_dp' },
            { text: '背包问题', link: '/contents/ch06/knanpsack_problem' },
          ]
        },
        {
          text: '贪心算法',
          collapsed: true,
          items: [
            { text: '中位数贪心', link: '/contents/ch07/README' },
          ]
        },
        {
          text: '高级数据结构',
          collapsed: true,
          items: [
            { text: '线段树', link: '/contents/ch08/seg_tree' },
          ]
        },
        {
          text: '高级图论',
          collapsed: true,
          items: [
            { text: '二分图', link: '/contents/ch09/README' },
          ]
        },
        {
          text: '动态规划进阶',
          collapsed: true,
          items: [
            { text: '空', link: '/contents/ch02/sort' },
          ]
        },
        {
          text: '附录',
          collapsed: true,
          items: [
            { text: '不常用算法', link: '/contents/appendix/README' },
          ]
        }
      ],
      '/interview/': [
        {
          text: '穷竭枚举',
          collapsed: true,
          items: [
            { text: '循环枚举', link: '/markdown-examples' },
            { text: '深度优先搜索', link: '/api-examples' },
            { text: '广度优先搜索', link: '/appendix'},
            { text: '指数型枚举', link: '/appendix'},
            { text: '组合型枚举', link: '/appendix'},
            { text: '排列型枚举', link: '/appendix'}
          ]
        }
      ]
    },

    socialLinks: [
      { icon: 'github', link: 'https://github.com/shubulan' }
    ]
  }
})