#include <gtest/gtest.h>
#include "libft.h"

TEST(resolve_path, absolute_path)
{
	char	*path = resolve_path(
		(char *)"/usr/bin", (char *)"/Home/absolute/path"
	);

	ASSERT_STREQ(path, "/Home/absolute/path");
	free(path);
}

TEST(resolve_path, dotdot)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)".."
	);

	ASSERT_STREQ(path, "/usr/bin");
	free(path);
}

TEST(resolve_path, relative_file_path_without_dot)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"file.txt"
	);

	ASSERT_STREQ(path, "/usr/bin/local/file.txt");
	free(path);
}

TEST(resolve_path, relative_dir_path_without_dot)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"hey/file.txt"
	);

	ASSERT_STREQ(path, "/usr/bin/local/hey/file.txt");
	free(path);
}

TEST(resolve_path, dotdot_from_one_dir)
{
	char	*path = resolve_path(
		(char *)"/usr", (char *)".."
	);

	ASSERT_STREQ(path, "/");
	free(path);
}

TEST(resolve_path, dotdot_root)
{
	char	*path = resolve_path(
		(char *)"/", (char *)".."
	);

	ASSERT_STREQ(path, "/");
	free(path);
}

TEST(resolve_path, dotdot_root_multi)
{
	char	*path = resolve_path(
		(char *)"/", (char *)"../.."
	);

	ASSERT_STREQ(path, "/");
	free(path);
}

TEST(resolve_path, dotdot_dir)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"../"
	);

	ASSERT_STREQ(path, "/usr/bin");
	free(path);
}

TEST(resolve_path, dotdot_dir_one_subdir)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"../document"
	);

	ASSERT_STREQ(path, "/usr/bin/document");
	free(path);
}

TEST(resolve_path, dotdot_dir_multi_subdir)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"../document/what"
	);

	ASSERT_STREQ(path, "/usr/bin/document/what");
	free(path);
}

TEST(resolve_path, dotdot_dir_multi)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"../../document/what"
	);

	ASSERT_STREQ(path, "/usr/document/what");
	free(path);
}

TEST(resolve_path, dotdot_dir_btw_subdir)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"../../document/../what"
	);

	ASSERT_STREQ(path, "/usr/what");
	free(path);
}

TEST(resolve_path, dotdot_dir_root)
{
	char	*path = resolve_path(
		(char *)"/", (char *)"../"
	);

	ASSERT_STREQ(path, "/");
	free(path);
}

TEST(resolve_path, dot)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"."
	);

	ASSERT_STREQ(path, "/usr/bin/local");
	free(path);
}

TEST(resolve_path, dot_multi)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"./."
	);

	ASSERT_STREQ(path, "/usr/bin/local");
	free(path);
}

TEST(resolve_path, dot_root)
{
	char	*path = resolve_path(
		(char *)"/", (char *)"."
	);

	ASSERT_STREQ(path, "/");
	free(path);
}

TEST(resolve_path, dot_root_multi)
{
	char	*path = resolve_path(
		(char *)"/", (char *)"./."
	);

	ASSERT_STREQ(path, "/");
	free(path);
}

TEST(resolve_path, dot_dir)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"./"
	);

	ASSERT_STREQ(path, "/usr/bin/local");
	free(path);
}

TEST(resolve_path, dot_dir_one_subdir)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"./what"
	);

	ASSERT_STREQ(path, "/usr/bin/local/what");
	free(path);
}

TEST(resolve_path, dot_dir_multi_subdir)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"./what/do"
	);

	ASSERT_STREQ(path, "/usr/bin/local/what/do");
	free(path);
}

TEST(resolve_path, dot_dir_multi)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"././what/do"
	);

	ASSERT_STREQ(path, "/usr/bin/local/what/do");
	free(path);
}

TEST(resolve_path, dot_dir_btw_subdir)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"././what/./do"
	);

	ASSERT_STREQ(path, "/usr/bin/local/what/do");
	free(path);
}

TEST(resolve_path, dot_dir_root)
{
	char	*path = resolve_path(
		(char *)"/", (char *)"./"
	);

	ASSERT_STREQ(path, "/");
	free(path);
}

TEST(resolve_path, dot_mixed)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)".././what/../do"
	);

	ASSERT_STREQ(path, "/usr/bin/do");
	free(path);
}

TEST(resolve_path, dotdot_in_from)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/../local", (char *)""
	);

	ASSERT_STREQ(path, "/usr/local");
	free(path);
}

TEST(resolve_path, dot_in_from)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/./local", (char *)""
	);

	ASSERT_STREQ(path, "/usr/bin/local");
	free(path);
}

TEST(resolve_path, dot_first_at_from)
{
	char	*path = resolve_path(
		(char *)"./usr/bin/local", (char *)""
	);
	char	*pwd;
	char	*temp;

	pwd = getcwd(NULL, 0);
	temp = pwd;
	pwd = ft_strjoin(pwd, "/usr/bin/local");

	ASSERT_STREQ(path, pwd);
	free(path);
	free(temp);
	free(pwd);
}

TEST(resolve_path, dotdot_first_at_from)
{
	char	*path = resolve_path(
		(char *)"../usr/bin/local", (char *)""
	);
	char	*pwd;
	char	*temp;

	pwd = getcwd(NULL, 0);
	temp = ft_strrchr(pwd, '/');
	*temp = '\0';
	temp = pwd;
	pwd = ft_strjoin(pwd, "/usr/bin/local");

	ASSERT_STREQ(path, pwd);
	free(path);
	free(temp);
	free(pwd);
}

TEST(resolve_path, whitespace)
{
	char	*path = resolve_path(
		(char *)"/usr    /bin/   local", (char *)"./   dir  /   /  s /   "
	);

	ASSERT_STREQ(path, "/usr    /bin/   local/   dir  /   /  s /   ");
	free(path);
}

TEST(resolve_path, multi_slash)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"./////////foo///bar/too//tar///"
	);

	ASSERT_STREQ(path, "/usr/bin/local/foo/bar/too/tar");
	free(path);
}

TEST(resolve_path, multi_slash_multi_dot)
{
	char	*path = resolve_path(
		(char *)"/usr/../////bin//local", (char *)"./////////./foo///../bar/./too//../tar///"
	);

	ASSERT_STREQ(path, "/bin/local/bar/tar");
	free(path);
}

TEST(resolve_path, dot_not_follwed_by_slash)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"..a"
	);

	ASSERT_STREQ(path, "/usr/bin/local/..a");
	free(path);
}

TEST(resolve_path, dot_ended)
{
	char	*path = resolve_path(
		(char *)"/usr/bin/local", (char *)"a."
	);

	ASSERT_STREQ(path, "/usr/bin/local/a.");
	free(path);
}
