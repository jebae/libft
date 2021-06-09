#include <gtest/gtest.h>
#ifdef __cplusplus
extern "C" {
#endif
#include "libft.h"
#ifdef __cplusplus
}
#endif

int	main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
#ifdef NEVER_END
	RUN_ALL_TESTS();
	while (1);
	return (0);
#else
	return RUN_ALL_TESTS();
#endif
}
